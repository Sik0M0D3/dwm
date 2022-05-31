Fonts:
------

  The "Material Design Icons" font i use is a dependency for the tags and a lot of the scripts that i use in my config repo, i get it from:
  - https://materialdesignicons.com/
  
    Just click the blue download button, save the zip, extract it, and from the fonts folder "MaterialDesign-Webfont-master/fonts/"
    change the ownership of "materialdesignicons-webfont.ttf" file to root and put it in "/usr/share/fonts/TTF/" dir (create it if doesn't exist),
    then do fc-cache (reboot if necessary) and voila!
    (Repeat the same process to update overwriting the old "materialdesignicons-webfont.ttf" file!).
  
  For the Fantasque Sans Mono and the Jet Brains Mono fonts i use the ones packaged in the official Arch repos:
  - https://archlinux.org/packages/community/any/ttf-fantasque-sans-mono/
  - https://archlinux.org/packages/community/any/ttf-jetbrains-mono/

Compositor:
-----------
  
  And for a compositor i don't use the picom from the official Arch repo i use jonaburg's fork from the aur:
  - https://aur.archlinux.org/picom-jonaburg-git.git
