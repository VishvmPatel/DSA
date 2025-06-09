#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a term in the polynomial
struct Term {
    int coeff;
    int exp;
};

// Class to represent a polynomial
class Polynomial {
private:
    vector<Term> terms;

public:
    // Function to create a polynomial from user input
    void create() {
        int n;
        cout << "Number of terms? ";
        cin >> n;
        terms.resize(n);

        cout << "Enter terms (coefficient exponent):\n";
        for (int i = 0; i < n; i++) {
            cin >> terms[i].coeff >> terms[i].exp;
        }
    }

    // Function to display the polynomial
    void display() const {
        for (size_t i = 0; i < terms.size(); i++) {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i != terms.size() - 1) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    // Function to add two polynomials
    static Polynomial add(const Polynomial& p1, const Polynomial& p2) {
        Polynomial result;
        size_t i = 0, j = 0;

        while (i < p1.terms.size() && j < p2.terms.size()) {
            if (p1.terms[i].exp > p2.terms[j].exp) {
                result.terms.push_back(p1.terms[i++]);
            } else if (p1.terms[i].exp < p2.terms[j].exp) {
                result.terms.push_back(p2.terms[j++]);
            } else {
                Term sum;
                sum.exp = p1.terms[i].exp;
                sum.coeff = p1.terms[i].coeff + p2.terms[j].coeff;
                result.terms.push_back(sum);
                i++;
                j++;
            }
        }

        // Add remaining terms of p1 and p2
        while (i < p1.terms.size()) {
            result.terms.push_back(p1.terms[i++]);
        }
        while (j < p2.terms.size()) {
            result.terms.push_back(p2.terms[j++]);
        }

        return result;
    }
};

int main() {
    Polynomial p1, p2;

    cout << "Enter first polynomial:\n";
    p1.create();

    cout << "Enter second polynomial:\n";
    p2.create();

    cout << "\nFirst Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    Polynomial p3 = Polynomial::add(p1, p2);
    cout << "Sum Polynomial: ";
    p3.display();

    return 0;
}