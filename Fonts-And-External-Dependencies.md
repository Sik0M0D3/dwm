Fonts:
------

  The Material Design Icons font i use is only for the tag icons and i get them from:
  - https://materialdesignicons.com/
  
    Just click the blue download button, save the zip, extract it, and from the fonts folder "MaterialDesign-Webfont-master/fonts/"
    change the ownership of "materialdesignicons-webfont.ttf" file to root and put it in "/usr/share/fonts/TTF/" (create it if doesn't exist) folder,
    then do fc-cache (reboot if necessary) and voila!
    (repeat the same process to update overwriting the old "materialdesignicons-webfont.ttf" file!).
  
  For the Fantasque Sans Mono and the Jet Brains Mono fonts i use the ones packaged in the official Arch repos.

Compositor:
-----------
  
  And for a compositor i don't use the picom from the official Arch repo i use jonaburg's fork from the aur:
  - https://aur.archlinux.org/picom-jonaburg-git.git
