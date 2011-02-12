#!/usr/bin/python
from lxml import etree

styleSheetFile = open("help.xsl", "r")
try:
    xsltDoc = etree.parse(styleSheetFile)
    transform = etree.XSLT(xsltDoc)

    for language in "en_US", "fr":
        print("Generating HTML files for the '" + language + "' language...")
        for file in "index", "menus", "alarms", "addedit", "toasts", "options", "license":
            print("Transforming file " + file + ".xml...")
            xmlFile = open(file + ".xml", "r")
            try:
                xmlDoc = etree.parse(xmlFile)
                resultTree = transform(xmlDoc, language=etree.XSLT.strparam(language.replace("_", "-")), extension="'.html'", sharedpath="'../'")
                resultFile = open(language + "/" + file + ".html", "w")
                try:
                    resultFile.write(str(resultTree))
                finally:
                    resultFile.close()
            finally:
                xmlFile.close()
finally:
    styleSheetFile.close()
