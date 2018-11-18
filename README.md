runit-session
=============

Simple session manager using runit

All services in this repo are just examples. The only two things ready to use are runit-session and hangit

Why?
====
Because you don't want your whole session to crash while you are experimenting with your window manager


How to use:
===========

Clone the repo:
```
$ git clone https://github.com/stiletto/runit-session.git ~/.runit-session
```
Compile hangit (or not, if you would not use oneshot-scripts):

```
$ cd ~/.runit-session
$ make
```
Create a directory for your services:
```
$ mkdir ~/.runit-session/services
```

Create some services, example for awesome:
```
$ mkdir ~/.runit-session/services/awesome
$ cat > ~/.runit-session/services/awesome/run <<EOF
#!/bin/sh
exec /usr/bin/awesome
EOF
$ chmod +x ~/.runit-session/services/awesome/run
```

Modify your .xinitrc:
```
cat >> ~/.xinitrc <<EOF
#!/bin/sh
exec ~/.runit-session/runit-session ~/.runit-session/services
EOF
