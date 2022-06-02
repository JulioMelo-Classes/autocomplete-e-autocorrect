import re
import sys

if len(sys.argv) == 1:
    print("É necessario o nome do arquivo de base!")
else:
    bruto = sys.argv[1]

formatado = "ingles.txt"

try:
    ref_arquivo = open(bruto,"r",encoding='utf-8')
    esc_arquivo = open(formatado,'a',encoding='utf-8')
    esc_arquivo.truncate(0)
    for linha in ref_arquivo:
        if len(linha)>1:
            numeros = ''
            for numero in linha:
                if numero.isdigit() == True:
                    numeros += numero

            frase = linha.strip()
            dictionary = {
                '.':'', 'º':'', '°':'', 'ª':'', '§':'', '£':'', '©':'', '¡':'', '<':'', '¹':'', '²':'',
                '³':'', '@':'', '#':'', '!':'', '$':'', '%':'', '¨':'', '&':'', '*':'', '(':'', ')':'', 
                '_':'', '+':'', '=':'', '/':'', ']':'', '[':'', '?':'', ':':'', ';':'', '¢':'', 
                '¬':'', '|':'', '{':'', '}':'', '>':'', '-':' ',
                'ç':"c", 'Ç':'C',
                'á':'a', 'â':'a', 'à':'a', 'ã':'a', 'ä':'a', 'Á':'A', 'À':'A', 'Â':'A', 'Ã':'A', 'Ä':'A',
                'é':'e', 'è':'e', 'ê':'e', 'ẽ':'e', 'ë':'e', 'É':'E', 'È':'E', 'Ê':'E', 'Ẽ':'E', 'Ë':'E',
                'í':'i', 'ì':'i', 'î':'i', 'ĩ':'i', 'ï':'i', 'Í':'I', 'Ì':'I', 'Î':'I', 'Ĩ':'I', 'Ï':'I',
                'ó':'o', 'ò':'o', 'ô':'o', 'õ':'o', 'ö':'o', 'Ó':'O', 'Ò':'O', 'Ô':'O', 'Õ':'O', 'Ö':'O',
                'ú':'u', 'ù':'u', 'û':'u', 'ũ':'u', 'ü':'u', 'Ú':'U', 'Ù':'U', 'Û':'U', 'Ũ':'U', 'Ü':'U'
            }
            transTable = frase.maketrans(dictionary)
            frase = frase.translate(transTable)
            frase.replace("-"," ")
            frase = re.sub(r"[^a-zA-Z, ]","",frase)
            frase = frase.lower()
            
            esc_arquivo.write(numeros +' '+frase+"\n")
    ref_arquivo.close()
    esc_arquivo.close()
except:
    print("Arquivo finalizado.")