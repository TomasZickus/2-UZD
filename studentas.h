#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class studentas {
private:
    std::string var_;
    std::string pav_;
    std::vector<int> paz_;
    int egz_;
    double rez_;
    double rez_med_;

public:
    // Konstruktoriai
    studentas();
    studentas(
        const std::string& var,
        const std::string& pav,
        const std::vector<int>& paz,
        int egz
    );

    // Kopijavimo ir perkėlimo konstruktoriai
    studentas(const studentas& other);
    studentas(studentas&& other) noexcept;

    // Kopijavimo ir perkėlimo priskyrimo operatoriai
    studentas& operator=(const studentas& other);
    studentas& operator=(studentas&& other) noexcept;

    // Destruktorius
    ~studentas();

    // Get'eriai
    const std::string& var() const;
    const std::string& pav() const;
    const std::vector<int>& paz() const;
    int egz() const;
    double rez() const;
    double rez_med() const;

    // Rezultatų skaičiavimas
    void paskaiciuoti_rezultatus();
};

#endif
