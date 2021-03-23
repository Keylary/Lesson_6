#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

// 1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака» : если пользователь вводит что - то кроме одного целочисленного значения, 
// нужно вывести сообщение об ошибке и предложить ввести число еще раз.Пример неправильных введенных строк :
        //  rbtrb
        //  nj34njkn
        //  1n

//bool checkInt(std::string a) {
//    
//    for (int i = 0; i < a.size(); ++i)
//    {
//        if (a[i] < '0' || a[i] > '9') {
//            std::cout << "Invalid input! ";
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    std::string a;
//    do
//    {
//        std::cout << "Enter an intager value: " << std::endl;
//        std::cin >> a;
//    } while (!checkInt(a));
//    return 0;
//}

// 2.Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.

//class Endll
//{};
//constexpr Endll endll;
//struct endll_ostream
//{
//    std::ostream& os;
//};
//
//inline endll_ostream operator << (std::ostream& os, Endll)
//{
//    return { os << "\n\n" << std::flush};
//}
//
//
//int main()
//{
//    std::cout << "A" << std::endl;
//    std::cout << endll;
//    std::cout << "A" << std::endl;
//    return 0;
//}
//


// 3.Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
    // virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.Метод спрашивает у пользователя, нужна ли ему еще одна карта 
            // и возвращает ответ пользователя в виде true или false.
    // void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
    //  void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
    // void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
// Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

//class Player : public GenericPlayer
//{
//public:
//    Player(const std::string& name = "");
//
//    bool isHitting() const override;
//    void win() const;
//    void lose() const;
//    void push() const;
//};
//
//Player::Player(const std::string& name) :
//    GenericPlayer(name)
//{}
//
//bool Player::isHitting() const
//{
//    std::cout << m_name << ", do you want a hit? (Y/N): ";
//    char response;
//    std::cin >> response;
//    return (response == 'y' || response == 'Y');
//}
//
//void Player::win() const
//{
//    std::cout << m_name << " wins." << std::endl;
//}
//
//void Player::lose() const
//{
//    std::cout << m_name << " loses." << std::endl;
//}
//
//void Player::push() const
//{
//    std::cout << m_name << " pushes." << std::endl;
//}

//  4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
        // virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
        // void FlipFirstCard() - метод переворачивает первую карту дилера.

//class House : public GenericPlayer
//{
//public:
//    House(const std::string& name = "House");
//    virtual bool isHitting() const;
//    void flipFirstCard();
//};
//
//House::House(const std::string& name) :
//    GenericPlayer(name)
//{}
//
//
//bool House::isHitting() const
//{
//    return (GetTotal() <= 16);
//}
//
//void House::flipFirstCard()
//{
//    if (!(m_Cards.empty()))
//    {
//        m_Cards[0]->Flip();
//    }
//    else
//    {
//        std::cout << "No card to flip!" << std::endl;
//    }
//}
//int main()
//{
//
//
//    return 0;
//}


// 5. Написать перегрузку оператора вывода для класса Card. \
// Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты. 
 
 
//class Card
//{
//public:
//    enum rank {
//        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
//        JACK, QUEEN, KING
//    };
//    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
//
//    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
//
//    int getValue() const;
//    void flip() { m_isFaceUp = !(m_isFaceUp); }
//
//    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
//
//private:
//    rank m_rank;
//    suit m_suit;
//    bool m_isFaceUp;
//};
//Card::Card(rank r /*= ACE*/, suit s, bool ifu)
//    : m_rank(r), m_suit(s), m_isFaceUp(ifu) {
//}
//
//int Card::getValue() const
//{
//    int value = 0;
//    if (m_isFaceUp)
//    {
//        value = m_rank;
//        if (value > 10)
//        {
//            value = 10;
//        }
//    }
//    return value;
//}
//
//std::ostream& operator<<(std::ostream& os, const Card& aCard)
//{
//    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
//        "10", "J", "Q", "K" };
//    const std::string SUITS[] = { "c", "d", "h", "s" };
//
//    if (aCard.m_isFaceUp)
//    {
//        os << RANKS[aCard.m_rank] << SUITS[aCard.m_suit];
//    }
//    else
//    {
//        os << "XX";
//    }
//
//    return os;
//}

//
//int main()
//{
//
//
//    return 0;
//}
//
