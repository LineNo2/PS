num_of_cards = int(input(), 10)
card_dict = {}
for i in range(0,num_of_cards):
    temp = input()
    card_dict[temp] = 0
    card_dict[temp] += 1
    print(i)
num_of_quried_cards = int(input(), 10)
for i in range(0,num_of_quried_cards):
    print(card_dict[input]).end(' ')

