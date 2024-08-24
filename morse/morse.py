#!/usr/bin/env python3

import argparse
import sys

# Define the Morse code dictionary
ALPHABET_TO_MORSE = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
    'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
    'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
    '6': '-....', '7': '--...', '8': '---..', '9': '----.', '0': '-----',
    ',': '--..--', '.': '.-.-.-', '?': '..--..', '/': '-..-.', '-': '-....-',
    '(': '-.--.', ')': '-.--.-', '&': '.-...', ':': '---...', ';': '-.-.-.',
    '=': '-...-', '+': '.-.-.', '-': '-....-', '/': '-..-.', '@': '.--.-.',
    ' ': '/'
}

REVERSE_CODE = {value: key for key, value in ALPHABET_TO_MORSE.items()}

def text_to_morse(text):
    return ' '.join(ALPHABET_TO_MORSE.get(char.upper(), '') for char in text)

def morse_to_text(morse_code):
    """Decode Morse code into a string."""
    morse_code += ' '  # Add a space at the end to handle the last Morse code
    decipher = ''
    citext = ''
    for char in morse_code:
        if char != ' ':
            citext += char
        else:
            if citext:
                if citext == '/':
                    decipher += ' '
                else:
                    decipher += REVERSE_CODE.get(citext, '')
                citext = ''
    return decipher

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Encode or decode Morse code.")
    parser.add_argument('text', nargs="?", help='Text to encode')
    parser.add_argument('-d', '--decode', action='store_true', help="Decode Morse code instead of encoding text")
    
    args = parser.parse_args()

    text = args.text if args.text else sys.stdin.read().strip()
    if args.decode:
        print(morse_to_text(text))
    else:
        print(text_to_morse(text))


