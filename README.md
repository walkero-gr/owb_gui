# owb_gui
A simple GUI for the OWB Browser for AmigaOS 4

This is a simple GUI for starting the new OWB Browser which must be in the same folder as the OWB_GUI. The reason that I created this is the need for something to run OWB with an easy way. This is version 0.7 and it is an alternative GUI of the OWB's one. 

Feel free to fix errors and/or put new features if you like! If you do, please inform me and send me the source code! If you release a newer version the source code must be included.

It was created with the help of EMPEROR for OS4.

**This version uses AISS Images. So you must have this installed.**

It doesn't write anything on hard disk unless you make changes at the preferences and save them, or edit your bookmarks. 
YOU MAY USE IT AT YOUR OWN RISK!

### Contact me ###
* My name is George Sokianos and you can contact me at (walkero gmail com).

### Thanks for their help and support ###
* Matthias Gietzelt and Vicente Gimeno for the Emperor program (http://os4depot.net/index.php?function=showfile&file=development/guitool/emperor.lha)
* Jorg Strohmayer for including the bookmark window of OWB_gui at the official OWB port and since then it is part of the official AmigaOS releases, in the contributed packages.

### Changelog ###
**v0.7 - free version : 2008-03-25 (http://os4depot.net/index.php?function=showfile&file=network/browser/owb_gui.lha)**

* New window with bookmarks implemented where you can add/edit/delete your bookmarks. They are saved automatically at any change and are loaded at program start.
* Fixed a bug with the arexx call of the google search field. Now if the OWB window is open you can send a new search from this field.
* A few more little bugs

**v0.6 - free version : 2008-02-04**

* Now supports the OWB 1.7 Rexx commands
* Fixed bugs from the preferences, when the user was saving empty strings (thanks pvanni)
* Checks if the OWB is started. If it is not, then it starts it.

**v0.5 - free version : 2008-01-31**

* You can set the home url through the preferences window.
* The extra window that the OWB opens now it doesn't appear.
* http://utilitybase.com/ added at the bookmarks menu

**v0.4 - free version : 2007-12-31**

* Google search text field added
* Preferences window added where you can set the window width, height and color depth. The changes can be saved and used as soon as you press the save button. You can edit these preferences with you beloved text editor too.

**v0.3 - free version : 2007-12-30**

* Major bug fixes. So no crashes here (Thanks to Vicente Gimeno 'Ami603')

**v0.2 - free version : 2007-12-28**

* A few fixes were made
* Support of AISS images

**v0.1 - free version : 2007-12-28**

* First version out. 
* Starts the OWB with parameter the URL that you select from the string object or the menu. Insert the url you want to visit and press the button "Go"
* You must have the OWB executable in the same folder
* An error GURU occurs on closing the window but with a continue there is no further problem
* The "Home" button opens the http://mail.yahoo.com web page