#include <iostream>
int chooseCreditCardType();
int digitCount(long long creditCardNo);
int findPrefix(long long creditCardNo, int count);
bool prefixLengthValidation(long long creditCardNo, int type, std::string &cardType);
bool validateCreditCard(long long creditCardNo, int cardLength);

int main()
{
    int cardLength;
    int type;
    char choice;
    std::string cardType;
    long long creditCardNo;
    bool firstValidationStatus, secondValidation;
    std::cout << '\n'
              << "******CREDIT CARD VALIDATOR******" << '\n';

    do
    {
        cardType = " ";
        type = chooseCreditCardType();

        std::cout << "Enter the credit card number : ";
        std::cin >> creditCardNo;

        firstValidationStatus = prefixLengthValidation(creditCardNo, type, cardType);

        if (firstValidationStatus)
        {
            cardLength = digitCount(creditCardNo);
            secondValidation = validateCreditCard(creditCardNo, cardLength);

            if (secondValidation)
            {
                std::cout << " VALID " << cardType << " Credit Card"
                          << "\n"
                          << "\n";
            }
            else
            {
                std::cout << " INVALID " << cardType << " Credit Card"
                          << "\n"
                          << "\n";
            }
        }

        std::cout << "Do you want to check again?(Y/N): ";
        std::cin >> choice;
        choice = toupper(choice);

    } while (choice != 'N');

    std::cout << "Thank you for using Credit Card Validator";

    return 0;
}

int chooseCreditCardType()
{
    int choice = 0;
    int type;
    do
    {
        std::cout << "**************************************" << '\n';
        std::cout << "1. American Express (Prefix: 34, or 37 )" << '\n';
        std::cout << "2. MasterCard (Prefix: 51 through 55 )" << '\n';
        std::cout << "3. Visa (Prefix: 4 )" << '\n';
        std::cout << "4. Diners Club and Carte Blanche (Prefix: 36, 38, or 300 through 305 )" << '\n';
        std::cout << "5. Discover (Prefix: 6011 )" << '\n';
        std::cout << "6. JCB (Prefix: 2123 or 1800 )" << '\n';
        std::cout << "7. JCB (Prefix: 3 )" << '\n';
        std::cout << "**************************************" << '\n';

        std::cout << "Enter your credit type (1 -7): ";
        std::cin >> choice;
        std::cin.clear();
        fflush(stdin);
    } while (!(choice < 8 && choice > 0));

    type = choice;
    return type;
}

int digitCount(long long creditCardNo)
{
    // counting digits in a given long long
    if (creditCardNo == 0)
    {
        return 1;
    }

    int count = 0;

    while (creditCardNo != 0)
    {
        creditCardNo = creditCardNo / 10;
        count++;
    }
    return count;
}

int findPrefix(long long creditCardNo, int count)
{
    for (int i = 0; i < count; i++)
    {
        creditCardNo = creditCardNo / 10;
        // std::cout << creditCardNo<<'\n' ;
    }

    return creditCardNo;
}

bool prefixLengthValidation(long long creditCardNo, int type, std::string &cardType)
{

    int prefix, prefix2;
    int numberOfDigitsInCard = digitCount(creditCardNo);

    switch (type)
    {
    case 1:

        prefix = findPrefix(creditCardNo, 13); // American express card length = 15 & prefix is first 2 digits, (15 - 2)

        if (numberOfDigitsInCard == 15 && (prefix == 34 || prefix == 37))
        {
            cardType = "American Express";
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! American express card number must have exactly 15 digits and prefix should be 34 or 37***"
                      << "\n";
            return false;
        }
        break;

    case 2:

        prefix = findPrefix(creditCardNo, 14); // MasterCard card length = 16 & prefix is first 2 digits, (16 - 2)

        if (numberOfDigitsInCard == 16 && (prefix == 51 || prefix == 52 || prefix == 53 || prefix == 54 || prefix == 55))
        {
            cardType = "Master Card";
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! MasterCard card number must have exactly 16 digits and prefix should be 51 through 55***"
                      << "\n";
            return false;
        }
        break;

    case 3:

        prefix = findPrefix(creditCardNo, numberOfDigitsInCard - 1); // Visa card length = 13/16 & prefix is first 1 digit, (13 - 1) or (16 -1)

        if ((numberOfDigitsInCard == 13 || numberOfDigitsInCard == 16) && prefix == 4)
        {
            cardType = "Visa";
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! We saw card number must have exactly 13 or 16 digits and prefix should be 4***"
                      << "\n";
            return false;
        }
        break;

    case 4:

        prefix = findPrefix(creditCardNo, 12);  // Diners Club and Carte Blanche card length = 14 & prefix is first 2 digits, (14 - 2)
        prefix2 = findPrefix(creditCardNo, 11); // Diners Club and Carte Blanche card length = 14 & prefix is first 3 digits, (14 - 3)

        if (numberOfDigitsInCard == 14 && (prefix == 36 || prefix == 38))
        {
            std::cout << "prfix: " << prefix;
            return true;
        }
        else if (numberOfDigitsInCard == 14 && (prefix2 == 300 || prefix2 == 301 || prefix2 == 302 || prefix2 == 303 || prefix2 == 304 || prefix2 == 305))
        {
            std::cout << "prfix2: " << prefix2;
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! Diners Club and Carte Blanche card number must have exactly 14 digits and prefix should be 36,38 or 300 through 305***"
                      << "\n";
            return false;
        }
        break;

    case 5:
        prefix = findPrefix(creditCardNo, 12); // Discover card length = 16 & prefix is first 4 digits, (16 - 4)

        if (numberOfDigitsInCard == 16 && prefix == 6011)
        {
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! Discover card number must have exactly 16 digits and prefix should be 6011***"
                      << "\n";
            return false;
        }
        break;
    case 6:

        prefix = findPrefix(creditCardNo, 11); // JCB card length = 15 & prefix is first 4 digits, (15 - 4)

        if (numberOfDigitsInCard == 15 && (prefix == 2123 || prefix == 1800))
        {
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! JCB card number must have exactly 15 digits and prefix should be 2123 or 1800***"
                      << "\n";
            return false;
        }
        break;

    case 7:

        prefix = findPrefix(creditCardNo, 15); // JCB card length = 16 & prefix is first digit, (16 - 1)

        if (numberOfDigitsInCard == 16 && prefix == 3)
        {
            return true;
        }
        else
        {
            std::cout << "***NOT A VALID CREDIT CARD! JCB card number must have exactly 16 digits and prefix should be 3***"
                      << "\n";
            return false;
        }
        break;
    }
}

bool validateCreditCard(long long creditCardNo, int cardLength)
{
    // Luhn's algorithm

    int temp, digit, doubledValue;
    int leftDigitSum = 0;
    int rightDigitSum = 0;

    // Loop for taking each digit card number from right to left
    // double the value of each digit which are at even position beginning from right to left.
    // assigning odd card length for even card length by adding 1.

    if (cardLength % 2 == 0)
    {
        cardLength = cardLength + 1;
    }

    // loop for taking each digit, if even card length-> cardLength+1;
    // position of number will be .....,even,odd,even,odd (Right to left)
    for (int i = cardLength; i >= 0; i--)
    {
        digit = creditCardNo % 10;
        creditCardNo = creditCardNo / 10;

        if (i % 2 == 0)
        { //
            doubledValue = digit * 2;

            int count = 0;

            temp = doubledValue;
            while (temp != 0) // checking no. of digits in double value
            {
                temp = temp / 10;
                count++;
            }

            // if double value is a two digit number then add those digits together
            if (count == 2)
            {
                for (int j = 0; j < 2; j++)
                {
                    digit = doubledValue % 10;
                    doubledValue = doubledValue / 10;
                    leftDigitSum = leftDigitSum + digit;
                }
            }
            else
            {
                leftDigitSum = leftDigitSum + doubledValue;
            }
        }
        else
        {
            rightDigitSum = rightDigitSum + digit;
        }
    }
    // std::cout << "leftDigitSum: " << leftDigitSum << '\n';
    // std::cout << "rightDigitSum: " << rightDigitSum << '\n';
    if ((leftDigitSum + rightDigitSum) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}