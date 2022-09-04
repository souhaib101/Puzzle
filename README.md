# Puzzle

## Hintergrund
In dieser Aufgabe arbeiten Sie mit Bilddateien, die Fragmente eines Gesamt-
bildes darstellen. Sie sollen ein Programm schreiben, das diese Dateien einliest, die Fragmente
anhand bestimmter Kriterien zusammenfügt, und Bilder wieder speichert.


## Erstellen des Programms
Nennen Sie Ihr Programm puzzle. Wir haben Ihnen ein Makefile
zur Verfügung gestellt, mit dem Sie Ihr Programm kompilieren, ausführen und testen sollen.
Ergänzen Sie das Makefile entsprechend der Kommentare im Makefile!

## Prüfen des Programms
Prüfen Sie mit make diff, ob Ihr Programm korrekt funktioniert,
und mit make valgrind, ob die Speicherverwaltung fehlerfrei ist. Wir haben diese beiden tar-
gets im Makefile bereits für Sie erstellt.

## Eingabe
Die Eingabe erfolgt über Bilddateien im PGM-Format (Portable Gray Map, ein
textbasiertes Rastergrafikformat für Graustufenbilder). Wir haben Ihnen einige Beispieldatei-
en bereitgestellt. Sie können die Bilder in einem Bildbetrachtungsprogramm öffnen, um sie
anzusehen; wenn Sie sie in einem Texteditor öffnen, sehen Sie deren Textdarstellung.
Es sollen mehrere Eingabedateien gleichzeitig verarbeitet werden können, die Sie zu diesem
Zweck untereinander zu einem einzelnen Bild zusammenfügen müssen.
Die Dateien sind wie folgt aufgebaut:
* Die erste Zeile enthält eine Magic Number. In ihr steht bei dieser
  Aufgabe immer nur P2.
* Die zweite Zeile enthält zwei Zahlen. Die erste beschreibt die
  Anzahl der Spalten des Bilds, die zweite Zahl beschreibt die
  Anzahl der Zeilen des Bilds.
* In der dritten Zeile steht der maximale Grauwert des Bilds, in unserem Fall immer 255.
* Dann folgen die Pixel des Bilds: 
   + Ein Pixel des Bildes wird durch einen Integer-Wert beschrieben, der seinen Grau-
     wert angibt. Es kann ganzzahlige Werte im Intervall [0, 255]annehmen. 0 entspricht
     schwarz, 255 entspricht weiß, und Zahlen dazwischen entsprechen je einem Grauwert.
   + Die Grauwerte sind durch Leerzeichen getrennt. Am Ende der Zeile steht noch ein
     Leerzeichen und ein Zeilenumbruch.
   + Alle Grauwerte der Pixel einer Zeile des Bildes stehen in einer Zeile der Datei.
   + Die verschiedenen Zeilen stehen untereinander.

## Zusammenfügen der Puzzleteile
Jedes eingegebene Bild stellt ein Puzzleteil dar, das
mit anderen passenden Puzzleteilen untereinander zu Gesamtbildern zusammengesetzt werden
soll. Sie erkennen zwei Eingabedateien, die direkt untereinander gelegt werden müssen dar-
an, dass die letzte Pixelzeile des oberen Bildes mit der ersten Pixelzeile des unteren Bildes
übereinstimmt. Sie sollen alle zueinander passenden Puzzlestücke identifizieren und zu Bildern
zusammensetzen.
* Fügen Sie die beiden identischen Randzeilen passender Puzzlestücke nur einmal, also nicht
  doppelt, in das Ausgabebild ein.
* Sie dürfen davon ausgehen, dass jedes Puzzleteil oben und unten jeweils zu maximal einem
  anderen Puzzleteil passt, und dass jedes Puzzleteil sich einfügen lässt.

## Ausgabe
Die Ausgabe erfolgt ebenfalls in einer PGM-Bilddatei. Die Ausgabedatei soll ge-
nauso aufgebaut sein wie die Eingabe-Dateien, und aus einem vollständig zusammengesetzten
Bild bestehen.

## Wichtige Anforderungen an das Programm
* Der Speicher für die eingelesenen Graustufenbilder muss dynamisch verwaltet werden.
* Insbesondere darf dieser also nicht statisch alloziert werden.
* Vor Beendigung des Programms muss der gesamte Speicher wieder freigegeben werden,
und geöffnete Dateien müssen geschlossen werden.
* Valgrind darf weder Speicherzugriffsverletzungen noch Speicherlecks melden. Valgrind
sollte auch keine anderen Fehler melden.
* Alle Funktionen sowie gegebenenfalls Datenstrukturen sollen in einer separaten Header-
datei deklariert werden.
* Ihr Algorithmus soll mit den von Ihnen allozierten Speicherbereichen arbeiten, und Datei-
zugriffe nur für das Einlesen in und Schreiben aus dem Speicher verwenden. Ihr Programm
darf nie mehr als eine Datei gleichzeitig geöffnet haben, und die Ausgabe-Datei darf nur
einmal geöffnet und geschlossen werden.
## Rückgabewerte  
Das Programm soll im Fehlerfall eine kurze aussagekräftige Meldung ausgeben und folgende
  Rückgabewerte haben:
  * 0, wenn alles ordnungsgemäß funktioniert.
  * 1, wenn nicht genügend Parameter übergeben werden.
  * 2, wenn eine der Ein- oder Ausgabedateien nicht geöffnet werden konnte oder es Fehler
  beim Lesen oder Schreiben von Dateien gab.
  * 3, wenn in der ersten Zeile der Eingabedatei nicht P2 steht. Sie dürfen aber davon aus-
  gehen, dass dort nie mehr als 9 Zeichen stehen.
## Aufruf des Programms
Das Programm bekommt beim Aufruf die Namen beliebig vieler
    Eingabedateien sowie den Namen einer Ausgabedatei übergeben. Werden mehrere Eingabe-
    dateien übergeben, so haben alle die gleiche Spaltenanzahl. Dabei stehen die Eingabedateien
    immer vor der Ausgabedatei. Hier zwei Beispiele:
    `./puzzle eingabe.pgm ausgabe.pgm`
    `./puzzle eingabe1.pgm eingabe2.pgm ausgabe.pgm`
## Viel Erfolg.