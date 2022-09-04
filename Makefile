compile:# TODO: Abhaengigkeiten einsetzen
	#kompiliere mit den Parametern zum Debuggen, Anzeigen aller Warnings so 
	# dass die Aufrufe beim Target testausgabe funktionieren und mit dem Standard c99. 

clean: # TODO: loesche die ausfuehrbare Datei und alle Testausgabedateien

diff: compile
	@sh diff.sh

valgrind: compile valgrind.sh
	@sh valgrind.sh




