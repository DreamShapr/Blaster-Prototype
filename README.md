# Blaster-Prototype
Files and tutorial for 3d printed blaster with full electronics, inspired by the SIMPLE BLASTER OS project by Chris Carpenter.

# Project Description
The blaster prototype is a fonctionnal prop for star wars fans. It include working trigger, sound, light, and displays with ammunition count.

# Project Warning 
Please keep in mind that this project is a prototype, and has some limitations. For example, the display are not independant as I intended them to be (still, because of color and format change, it is also cool), and the mp3 player drives too much power when added to other components like the displays, and it may crash the program with some sound files (logically not the ones included here, as i had tested them).
Also, even if it is not a problem, i found my protoype to be a little large.
I will works on a V2 version, with only one display (side) to reduce the size), and a V3 without display to get the full potential of the sound board.
I will also works on a rifle with much more functionnality (like independant displays, stun mode, etc...) for i will no longer be limited by the capacyty of the gun to hold components).
You are welcome to check for any updates here ! :) 

# Project Requirements
This project requires little to none IT skills, for i will try to walk you through the build, but it will require some hardware :

(every link is indicative, you don't have to use the exact same ones, as long as the dimensions are the sames)

- Soldering iron
- electronical wires (arduino Dupont ones would do fine, but personnally i like mines a little larger)
- Arduino nano (official or [not](https://www.amazon.fr/s?k=arduino+nano+elegoo&__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=21AOODUQ6L2EV&sprefix=arduino+nano+elegoo%2Caps%2C70&ref=nb_sb_noss_1))
- [Mp3 DFPlayer](https://www.amazon.fr/AZDelivery-DFPlayer-Arduino-compris-eBook/dp/B07Z5D1TX8/ref=sr_1_3_sspa?keywords=dfplayer+mini+mp3+arduino&qid=1680517477&sprefix=dfp%2Caps%2C74&sr=8-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) for aduino 
- Micro sd card (more than 2Gb)
- [Speaker](https://fr.aliexpress.com/item/32921436094.html?isdl=y&aff_fsk=_9znYgV&src=Connexity&aff_platform=aff_feeds&aff_short_key=_9znYgV&pdp_npi=2%40dis%21EUR%211.87%211.64%21%21%21%21%21%40%2166133252193%21afff&dp=16805211846515582166112021000008005&cn=318473&cv=a5930b23d6663d1663e90cd684112080)
- [128x64 Oled display](https://www.amazon.fr/SSD1306-dAffichage-Auto-Lumineuse-Compatible-Raspberry/dp/B08FD643VZ/ref=sr_1_1_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2EQB1QYQNF7EY&keywords=oled+display+arduino&qid=1680517523&sprefix=oled+display+arduino%2Caps%2C65&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- [128x32 Oled display](https://www.amazon.fr/Pi%C3%A8ces-Module-dAffichage-SSD1306-Couleur/dp/B08CDN5PSJ/ref=sr_1_1?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=U6U3LRYQYBV5&keywords=oled+display+arduino+0.91&qid=1680517611&sprefix=oled+display+arduino+0.91%2Caps%2C66&sr=8-1)
- [PushButton](https://www.amazon.fr/Ytian-Bouton-Momentan%C3%A9s-Poussoir-Interrupteur/dp/B07C845S2Q/ref=sr_1_22?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=32O9IRXOQR8O5&keywords=bouton+poussoir+2a+2+broches&qid=1680521309&sprefix=bouton+poussir+2a+2broche%2Caps%2C75&sr=8-22)
- [limit Switch](https://www.amazon.fr/UKCOCO-interrupteur-commutateur-bouton-poussoir-momentan%C3%A9/dp/B07MDJZJG5/ref=sr_1_6?keywords=bouton+fin+de+course&qid=1680521338&sprefix=boton+fin+de+co%2Caps%2C73&sr=8-6)
- [Switch](https://www.amazon.fr/Youmile-interrupteurs-glissi%C3%A8re-verticaux-interrupteur/dp/B08SM2HHNR/ref=sr_1_12?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=HISOVMCE42Q9&keywords=interrupteur%2Barduino&qid=1680521400&sprefix=inerrupteur%2Barduino%2Caps%2C72&sr=8-12&th=1)
- [Laser](https://www.amazon.fr/RUNCCI-YUN-Photor%C3%A9sistance-R%C3%A9sistance-D%C3%A9pendant-Lumi%C3%A8re/dp/B08N1F5YBG/ref=sr_1_2_sspa?adgrpid=1353499750845157&hvadid=84594162209376&hvbmt=be&hvdev=c&hvlocphy=126407&hvnetw=o&hvqmt=e&hvtargid=kwd-84594261404324%3Aloc-66&hydadcr=27708_2269046&keywords=arduino+laser&qid=1680522013&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) or led.
- 9V battery
- [9V battery connectors](https://www.amazon.fr/Connecteur-Coupleur-Branchement-Raccordement-Clips/dp/B00JW80Y8O/ref=asc_df_B00JW80Y8O?tag=bingshoppin0f-21&linkCode=df0&hvadid=80608002580871&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=&hvtargid=pla-4584207577903478&psc=1)
- 2 bolts (CHC M4x2)
- 2 springs (I used pen ones)


# Tutorial

## Wiring diagram : 
You can change most of the pins, except for the ones connected to the displays (SDA and SCL), the Vin, 5V, 3V3 and GND.
If you decide to use a led in place of the laser (for safety reasons, for example), you can wire it the same way, but don't forget to add a resistor.
![Wiring](https://user-images.githubusercontent.com/129743177/229611605-f5bdc5fa-e650-42f9-a495-9acd02763e56.PNG)

## Sd card configuration
Copy the content of the folder "mp3" on the root of the card. It contains the sound files names in the format (000X.mp3).

## Arduino programming
You can find the code in the Src folder. After the wiring, if you are not certain that your components works fine, you can test them one by one with arduino tutorials before uploading the file BlasterV1_1.ino.

## 3d printing the blaster
You can find the files [here](https://cults3d.com/en/users/DreamShapr/creations). The files of the upgraded versions will also be available on here.

## Assembly



