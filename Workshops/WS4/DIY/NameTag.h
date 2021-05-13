/*
Name: Filipe da Cunha de Freitas
ID: 155737190
email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-16
*/

#ifndef SDDS_TAG_H
#define SDDS_TAG_H

namespace sdds {

    class NameTag {
    private:
        char* m_name;
        long long m_extension;

        void setEmpty();
        void setName(const char* Cstr);
        void setExtension(const long long extension);
        void addExtension();
        bool isEmpty() const;
        bool isValid(long long extension) const;
        long isValid() const;

    public:
        NameTag();
        NameTag(const char* name);
        NameTag(const char* name, long long extension);

        NameTag& read();
        std::ostream& print()const;

        ~NameTag();
    };
};

#endif // !SDDS_BOX_H

