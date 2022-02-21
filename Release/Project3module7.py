import re
import string

def histogram():
    # Start writing the content to file 
    f = open("frequency.dat", "w")
     # Open the file in read mode
    text = open("txtfile.txt", "r")
  
    # Create an empty dictionary
    d = dict()
  
    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()
  
        # Convert the characters in line to 
        # lowercase to avoid case mismatch
        line = line.lower()
  
        # Remove the punctuation marks from the line
        line = line.translate(line.maketrans("", "", string.punctuation))
  
        # Split the line into words
        words = line.split(" ")
  
        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in d:
                # Increment count of word by 1
                d[word] = d[word] + 1
            else:
                # Add the word to dictionary with count 1
                d[word] = 1
  
    # write the contents of dictionary to frequency.dat   
    for key in list(d.keys()):
        strValue = str(key)+" "+str(d[key])
        f.write(strValue+"\n")
   
    f.close() # close the file writing operation
    print("frequency.dat written Successful\n")
    print("Creating and displaying a histogram\n")
    # Read the frequency.dat file and display a histogram
    file = open("frequency.dat", "r")
    for lines in file:
        data = lines.split() #split string into a list
        name = data[0]
        fre  = int(data[1])
        newString = ""
        newString = name+" "
        #print(name," "),
        for x in range(fre):
           newString +="*";

        print(newString)

    return 0
def frequency(item):
    value = 0;
        # Open the file in read mode
    text = open("txtfile.txt", "r")
  
    # Create an empty dictionary
    d = dict()
  
    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()
  
        # Convert the characters in line to 
        # lowercase to avoid case mismatch
        line = line.lower()
  
        # Remove the punctuation marks from the line
        line = line.translate(line.maketrans("", "", string.punctuation))
  
        # Split the line into words
        words = line.split(" ")
  
        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in d:
                # Increment count of word by 1
                d[word] = d[word] + 1
            else:
                # Add the word to dictionary with count 1
                d[word] = 1
    
    if item in list(d.keys()):
        value= d[item]
    
    return value

def freq():
    # Open the file in read mode
    text = open("txtfile.txt", "r")
  
    # Create an empty dictionary
    d = dict()
  
    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()
  
        # Convert the characters in line to 
        # lowercase to avoid case mismatch
        line = line.lower()
  
        # Remove the punctuation marks from the line
        line = line.translate(line.maketrans("", "", string.punctuation))
  
        # Split the line into words
        words = line.split(" ")
  
        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in d:
                # Increment count of word by 1
                d[word] = d[word] + 1
            else:
                # Add the word to dictionary with count 1
                d[word] = 1
  
    # Print the contents of dictionary
    print("Words  : Frequency")
    for key in list(d.keys()):
        print(key, ":", d[key])
    return 0