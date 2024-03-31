#!/bin/sh
# Reset Parallels Desktop's trial and generate a casual email address to register a new user
rm /private/var/root/Library/Preferences/com.parallels.desktop.plist /Library/Preferences/Parallels/licenses.xml
jot -w pdu%d@gmail.com -r 1
