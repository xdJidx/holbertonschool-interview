#!/usr/bin/python3
"""0-making_change"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of
    coins needed to meet a given amount total.

    Arguments:
    coins -- a list of the values of the coins in the pile
    total -- the total amount to be reached

    Returns:
    The fewest number of coins needed to meet the total amount
    """
    if total <= 0:
        return 0

    # Initialisation du tableau dp avec des valeurs infinies
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Aucune pièce n'est nécessaire pour un total de 0

    # Calculer le nombre minimal de pièces pour chaque montant jusqu'à total
    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    # Si dp[total] est encore infini, cela signifie qu'on ne peut pas atteindre
    # total avec les pièces données
    if dp[total] == float('inf'):
        return -1
    else:
        return dp[total]
