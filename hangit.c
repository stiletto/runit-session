#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define xstr(s) str(s)
#define str(s) #s

setarg(char *argv0) {
    int parent = getppid();
    char procname[sizeof("/proc/" xstr(UINT_MAX) "/cmdline")];
    snprintf(procname, sizeof(procname), "/proc/%d/cmdline", parent);
    int o = open(procname, O_RDONLY);
    if (o < 0) return;
    char parentname[16];
    int cnt = read(o, parentname, sizeof(parentname));
    close(o);
    if (cnt < 0) return;
    for (o=0; o<cnt-1; o++)
        if (parentname[o]=='\0')
            parentname[o]=' ';
    parentname[cnt-1] = '\0';
    cnt = strlen(argv0)+1;
    for (o = snprintf(argv0, cnt, "hangit <%s>\0", parentname);o<cnt;o++)
        argv0[o] = '\0';
}

int main(int argc, char *argv[]) {
    setarg(argv[0]);
    pause();
}
