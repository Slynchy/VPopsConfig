# VPopsConfig
A tool for compiling/decompiling __sce_menuinfo for the PSVita PSOne emulator

# How to use
Rip the __sce_menuinfo for the game you want using standard tricks (EML, Rejuvenate, etc.)

Then use the tool to decompile it like so:

  VPopsConfig.exe -d [source __sce_menuinfo file]

This will give you a file that you can edit more easily. When you're done, run this:

  VPopsConfig.exe -c [modified __sce_menuinfo file]

To get the file back to normal.

# How to compile
It doesn't use anything out of the ordinary, should compile on Windows no problem. 
Compiling on Mac/Linux though? Never tried; someone try it and let me know!
