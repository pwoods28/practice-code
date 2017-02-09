import sys
import platform
import imp
import datetime
import requests
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET
    print 'Was unable to import cElementTree'


f = open(r'C:\Users\Patrick\Desktop\Python_Project\log.txt','w')
url = "http://api.smartenergygroups.com/streams/4fe5ef7f3b2fda7.xml?sort_option=dd&point_limit=5"
XML = requests.get(url, stream = True)
#print resp.content 
#tree = ET.fromstring(resp.content)

array = []

for event, elem in ET.iterparse(XML.raw):
    if elem.tag == 'value':
        array.append(float(elem.text))
        print elem.text

print array
    
    #print event
    #print elem
    #print elem.text

#root = tree.getroot()

#stream_list = tree.findall('stream')


#for x in tree:
    #print x.tag, x.attrib

#tree.find('value')


# Write date/time
#
f.write(str(datetime.datetime.now())+ '\n')
f.write('Test Write\n')
f.write('By Patrick Woods\n')




# Python info
#
f.write("Python EXE : " + sys.executable + "\n")
f.write("Architecture : " + platform.architecture()[0] + "\n")
#f.write("Path to arcpy : " + imp.find_module("arcpy")[1] + "\n")
f.close()
