#include <iostream>
#include <string>

// Abstract product class
class Document {
public:
    virtual void open() = 0; // Pure virtual function
    virtual ~Document() = default;
};


// Concrete product - PDF document
class PDFDocument : public Document {
public:
    void open() override {
        std::cout << "Opening PDF document." << std::endl;
    }
};

// Concrete product - Word document
class WordDocument : public Document {
public:
    void open() override {
        std::cout << "Opening Word document." << std::endl;
    }
};


// Abstract creator class
class DocumentCreator {
public:
    virtual Document* createDocument() = 0; // Factory method
    virtual ~DocumentCreator() = default;
};


// Concrete creator for PDF documents
class PDFCreator : public DocumentCreator {
public:
    Document* createDocument() override {
        return new PDFDocument(); // Create and return PDF document
    }
};

// Concrete creator for Word documents
class WordCreator : public DocumentCreator {
public:
    Document* createDocument() override {
        return new WordDocument(); // Create and return Word document
    }
};


int main() {
    // Create a PDF document using the factory method
    DocumentCreator* pdfCreator = new PDFCreator();
    Document* pdfDoc = pdfCreator->createDocument();
    pdfDoc->open(); // Output: Opening PDF document.
    
    // Create a Word document using the factory method
    DocumentCreator* wordCreator = new WordCreator();
    Document* wordDoc = wordCreator->createDocument();
    wordDoc->open(); // Output: Opening Word document.
    
    // Cleanup
    delete pdfDoc;
    delete wordDoc;
    delete pdfCreator;
    delete wordCreator;

    return 0;
}

