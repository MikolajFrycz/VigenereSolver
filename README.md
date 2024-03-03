# VigenereSolver
This program can encrypt, decrypt and break vigenere-ciphered messages.
It is a command line program used with input arguments adequate to the mode which we would like to use.
## Manual
This is a command line program used with input arguments adequate to the mode which we would like to use.

1. Encrypt example:
   
V-Cipher --en -i messagetoencrypt.txt -k key.txt -o outputmessage.txt

3. Decrypt example (when key is known):
   
V-Cipher --de -i messagetodecrypt.txt -k key.txt -o outputmessage.txt

4. Break cipher (unknown key):
   
V-Cipher --br -i messagetobreak.txt -o outputmessage.txt

### Important
The shorter the message, the lower the chance of succesfully breaking the cipher in the third mode. 
E.g. A 250-letter long encrypted message can be broken if the key was not longer than 4 charachters. If the message is longer than 2000 words, then the cipher can be broken even if the key was as long as 25 characters.
