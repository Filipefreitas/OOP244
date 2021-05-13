/*
Name: Filipe da Cunha de Freitas
ID: 155737190
email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-16
*/

#ifndef SDDS_BOX_H
#define SDDS_BOX_H

namespace sdds {

    class Box {
    private:
        char* m_contentName;    // the conent name pointer:
        // this pointer holds the name of the material to be kept in the box
        // dynamically
        int m_width;            // The dimensions of the box in Inches
        int m_height;
        int m_length;
        int m_contentVolume;   // the content volume:
                                // This variable holds the volume of the material currently  the box in Cubic Inches

        void setName(const char* Cstr);
        void setUnusable();
        bool isUnusable()const;

    public:
        Box();
        Box(int sideLength, const char* contentName = nullptr);
        Box(int width, int height, int length, const char* contentName = nullptr);
        bool hasContent()const;

        int capacity()const;
        int quantity()const;
        Box& setContent(const char* contentName);
        std::ostream& display()const;
        Box& add(int i);
        Box& add(Box& B);

        ~Box();
    };
};

#endif // !SDDS_BOX_H
