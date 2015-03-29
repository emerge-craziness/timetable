# timetable
Simple timetable utility (just for fun but useful).
<br><br>
1. Run `make` to compile this.<br>
2. Copy `timetable` from here to your `~/` and edit it as you need.<br>
3. Run `make install` to create a symlink in `/usr/bin/tt`.<br>
4. Run `make deinstall` to delete it.<br><br>
Usage:<br>
`tt [-t | -n | -d <number>]`<br>
`-t` means "today"<br>
`-n` means "next day"<br>
`-d <number>` to specify the day number<br>
<br><br>
`timetable` file syntax:<br>
[uppercaseDayOfWeek]<br>
..some your stuff<br>
[end]
