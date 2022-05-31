Fonts:
------
- The Material Design Icons font i use is only for the tag icons and i get them from: https://materialdesignicons.com/
Just click the blue download button, save the zip, extract it, and from the fonts folder (e.g MaterialDesign-Webfont-master/fonts/)
I change the ownership of "materialdesignicons-webfont.ttf" file to root and put it in my "/usr/share/fonts/TTF/" folder with sudo mv,
then i do a fc-cache (and reboot if necessary) and voila (repeat the same process to update overwriting the old "materialdesignicons-webfont.ttf" file!).

- For the Fantasque Sans Mono and the Jet Brains Mono fonts i use the ones packaged in the official Arch repos.

Compositor:
-----------
- For a compositor i don't use the picom from the official Arch repos i use jonaburg's fork from the aur https://aur.archlinux.org/picom-jonaburg-git.git
