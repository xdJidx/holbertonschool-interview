#!/usr/bin/python3
"""__name__ = "utf8_validation"
"""


def validUTF8(data):
    """
    Détermine si une liste d'entiers représente un caractère UTF-8 valide
    """
    # Boucle à travers chaque entier dans la liste
    i = 0
    while i < len(data):
        # Détermine le nombre de bits de préfixe pour ce caractère UTF-8
        if (data[i] & 0b10000000) == 0:  # 1 octet
            length = 1
        elif (data[i] & 0b11100000) == 0b11000000:  # 2 octets
            length = 2
        elif (data[i] & 0b11110000) == 0b11100000:  # 3 octets
            length = 3
        elif (data[i] & 0b11111000) == 0b11110000:  # 4 octets
            length = 4
        else:
            return False  # Invalide

        # Vérifie les octets suivants pour un caractère multioctet
        i += 1
        for j in range(length - 1):
            if i >= len(data) or (data[i] & 0b11000000) != 0b10000000:
                return False  # Invalide
            i += 1

    return True
