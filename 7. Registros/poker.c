#include <stdio.h>

enum suit {
  Diamonds,
  Heart,
  Clubs,
  Spades
};

enum value {
  Two = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

typedef struct {
  enum suit suit;
  enum value value;
} Card;

typedef enum {
  Nothing,
  Pair,
  TwoPair,
  ThreeOfAKind,
  Straight,
  Flush,
  FullHouse,
  FourOfAKind,
  StraightFlush,
  RoyalFlush
} PokerHand;

void sort_cards(Card cards[5]){
    Card aux;
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            if (cards[i].value < cards[j].value){
                aux = cards[i];
                cards[i] = cards[j];
                cards[j] = aux;
            }
        }
    }
}

int same_suit(Card cards[5]){
  for (int i = 1; i < 5; i++)
    if (cards[0].suit != cards[i].suit)
      return 0;

  return 1;
}

int in_sequence(Card cards[5]){
  for (int i = 0; i < 4; i++)
    if (cards[i].value - 1 != cards[i + 1].value)
      return 0;

  return 1;
}

int n_of_a_kind(Card cards[5], int n){
  for (int i = 0; i + n - 1 < 5; i++)
    if (cards[i].value == cards[i + n - 1].value)
      return 1;

  return 0;
}

int quant_pairs(Card cards[5]){
  int n = 0;
  for (int i = 0; i < 4; i++) {
    if (cards[i].value == cards[i + 1].value){
      n++; //+1 par;
      i++; //pula duas posições quando acha um par
    }
  }
  return n;
}

PokerHand checkHand(Card cards[5]){
  sort_cards(cards);

  if (in_sequence(cards)){
    if (same_suit(cards)){
      if (cards[0].value == Ace)
        return RoyalFlush;
      
      return StraightFlush;
    }
    return Straight;
  }

  if (n_of_a_kind(cards, 4))
    return FourOfAKind;
  
  if ((cards[0].value == cards[1].value && cards[2].value == cards[4].value)
      || (cards[0].value == cards[2].value && cards[3].value == cards[4].value))
    return FullHouse;
  
  if (same_suit(cards))
    return Flush;
  
  if (n_of_a_kind(cards, 3))
    return ThreeOfAKind;

  int quant_pairs_cards = quant_pairs(cards);
  if (quant_pairs_cards == 2)
    return TwoPair;
  
  if (quant_pairs_cards == 1)
    return Pair;

  return Nothing;
}


int main() {
    Card hands[][5] = {
        {  // Royal Flush
            { Diamonds, Ace },
            { Diamonds, King },
            { Diamonds, Queen }, 
            { Diamonds, Jack }, 
            { Diamonds, Ten } 
        },
        { // Full house
          { Heart, Jack },   
          { Spades, Jack },   
          { Clubs, Jack },     
          { Spades, Two  },    
          { Heart, Two } 
        },   
        { // Three of a Kind
          { Diamonds, Ten }, 
          { Spades, Seven },  
          { Diamonds, Four },  
          { Spades, Four  },   
          { Heart, Four } 
        },  
        { // Pair
          { Spades, Ace  },  
          { Heart, Jack },    
          { Spades, Jack },    
          { Heart, Seven },    
          { Clubs, Four } 
        },  
        { // High Card (No pair)
          { Clubs, Nine },   
          { Heart, Seven },   
          { Diamonds, Six },   
          { Spades, Four  },   
          { Heart, Two } 
        },   
    };
    Card myCards[5];
    Card oponentCards[5];
    
    unsigned handIndex;
    scanf("%u", &handIndex);
    for(int i = 0; i < 5; i++) {
        myCards[i] = hands[handIndex][i];
        scanf("%u %u", &oponentCards[i].suit, &oponentCards[i].value);
    }
    PokerHand myHand = checkHand(myCards);
    PokerHand oponentHand = checkHand(oponentCards);
    if (myHand > oponentHand) {
        switch(myHand) {
            case RoyalFlush:
                printf("É... simplesmente não tinha como me bater!\n");
                break;
            case StraightFlush:
            case FourOfAKind:
            case FullHouse:
                printf("Já era! Você não tinha chance!\n");
                break;
            case Flush:
            case Straight:
            case ThreeOfAKind:
                printf("É boy! Quem sabe da próxima vez...\n");
                break;
            default:
                printf("Tive sorte!\n");
        }
    }
    else if (oponentHand > myHand) {
        printf("Não valeu! Cê tá roubando!!!\n");
    }
    else if (myCards[0].value > oponentCards[0].value) {
        printf("Ufa! Por pouco!");
    }
    else {
        printf("Nan!! Bicho melado da gota!\n");
    }
    return 0;
}