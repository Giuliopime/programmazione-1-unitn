# Apri terminal Ctrl-Alt-T

# Vedere il manuale di un comando
man comando
# oppure
commando --help

# Spostarsi tra le cartelle
cd

# Mostra la cartella "directory" corrente
pwd # Print working directory

# Lista file di una cartella
ls
ls -l # Sotto forma di lista dettagliata
ls -a # Mostra anche i file nascosti (che iniziano con il punto .)
ls -h # Mostra dimensioni dei file più leggibili
ls -R # Mostra anche sotto cartelle ricorsivamente

# Creare una cartella
mkdir cartella
mkdir "cartella con spazi"

# Mostra il contenuto di un file
cat file.txt
cat -n file.txt # Mette il numero delle righe

# Creare un file
touch nome-file

# Copiare un file
cp file.txt cartella/file-copiato.txt
cp -n file.txt cartella/nuovo-nome.txt # Non overwrita i file già esistenti
cp -r cartella Desktop/archivio # Copia ricorsivamente le cartelle

# Muovere un file
mv file.txt cartella/file.txt
mv file.txt nuovo-nome.txt # Funziona come rinonima file

# Eliminare file e cartelle
rm file
rm cartella
rm -r cartella # Rimuove ricorsivamente i file della cartella
rmdir # Rimuove una cartella
rmdir -r # Rimuove una cartella ed il suo contenuto

# Pulire il terminale
clear

# Chiudere il terminale
exit