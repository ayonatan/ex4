#ifndef MTM_HW4_EXCEPTION_H
#define MTM_HW4_EXCEPTION_H

class DeckFileNotFound : public std::exception
{
    public:
        DeckFileNotFound() = default;
        ~DeckFileNotFound() = default;
        const char* what() const noexcept override 
        {
            return "Deck File Error: File not found";
        }
};

class DeckFileFormatError : public std::exception
{
    //private:
    //    int m_numOfLine;
    public:
        DeckFileFormatError()=default; /*: m_numOfLine(){}*/
        ~DeckFileFormatError() = default;
        const char* what() const noexcept override
        {
            return "File format error in line";
        }
};

class DeckFileInvalidSize : public std::exception
{
    public:
        DeckFileInvalidSize() = default;
        ~DeckFileInvalidSize() = default;
        const char* what() const noexcept override
        {
            return "Deck File Error: Deck size is invalid";
        }
};
#endif