#!/bin/sh


echo "** Erstelle Testausgabedateien! **"
./puzzle hhu_puzzleteil1.pgm hhu_puzzleteil2.pgm test_hhu_out.pgm
./puzzle berge_puzzleteil3.pgm berge_puzzleteil2.pgm berge_puzzleteil1.pgm test_berge_out.pgm
./puzzle muenzen_puzzleteil3.pgm muenzen_puzzleteil1.pgm muenzen_puzzleteil2.pgm muenzen_puzzleteil5.pgm muenzen_puzzleteil4.pgm test_muenzen_out.pgm

echo "**"
echo "** Wenn die Ausgabe der folgenden Befehle leer ist, stimmen Ihre Ausgaben mit den Ausgaben der Vorgabe ueberein!"
echo "**"
diff test_hhu_out.pgm hhu_out.pgm
diff test_berge_out.pgm berge_out.pgm
diff test_muenzen_out.pgm muenzen_out.pgm
echo "**"
echo "** Ende der Tests "
echo "**"



