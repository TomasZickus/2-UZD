#include "studentas.h"
#include <algorithm>
#include <utility>


// Numatytoji konstruktoriaus realizacija
studentas::studentas()
    : egz_(0), rez_(0), rez_med_(0) {
}


// Parametrizuotas konstruktorius
studentas::studentas(
    const std::string& var,
    const std::string& pav,
    const std::vector<int>& paz,
    int egz
)
    : var_(var),
      pav_(pav),
      paz_(paz),
      egz_(egz),
      rez_(0),
      rez_med_(0) {
}


// Kopijavimo konstruktorius
studentas::studentas(const studentas& other)
    : var_(other.var_),
      pav_(other.pav_),
      paz_(other.paz_),
      egz_(other.egz_),
      rez_(other.rez_),
      rez_med_(other.rez_med_) {
}


// Perkėlimo konstruktorius
studentas::studentas(studentas&& other) noexcept
    : var_(std::move(other.var_)),
      pav_(std::move(other.pav_)),
      paz_(std::move(other.paz_)),
      egz_(other.egz_),
      rez_(other.rez_),
      rez_med_(other.rez_med_) {
}


// Kopijavimo priskyrimo operatorius
studentas& studentas::operator=(const studentas& other) {
    if (this != &other) {
        var_ = other.var_;
        pav_ = other.pav_;
        paz_ = other.paz_;
        egz_ = other.egz_;
        rez_ = other.rez_;
        rez_med_ = other.rez_med_;
    }

    return *this;
}


// Perkėlimo priskyrimo operatorius
studentas& studentas::operator=(studentas&& other) noexcept {
    if (this != &other) {
        var_ = std::move(other.var_);
        pav_ = std::move(other.pav_);
        paz_ = std::move(other.paz_);
        egz_ = other.egz_;
        rez_ = other.rez_;
        rez_med_ = other.rez_med_;
    }

    return *this;
}


// Destruktorius
studentas::~studentas() = default;


// Get'eriai

const std::string& studentas::var() const {
    return var_;
}

const std::string& studentas::pav() const {
    return pav_;
}

const std::vector<int>& studentas::paz() const {
    return paz_;
}

int studentas::egz() const {
    return egz_;
}

double studentas::rez() const {
    return rez_;
}

double studentas::rez_med() const {
    return rez_med_;
}


// Galutinio rezultato skaičiavimas
void studentas::paskaiciuoti_rezultatus() {
    double suma = 0;

    for (int sk : paz_)
        suma += sk;

    double nd_vidurkis =
        paz_.empty() ? 0 : suma / paz_.size();

    rez_ = 0.4 * nd_vidurkis + 0.6 * egz_;


    // Medianos skaičiavimas
    std::vector<int> surikiuoti = paz_;

    std::sort(surikiuoti.begin(), surikiuoti.end());

    double nd_mediana = 0;

    if (!surikiuoti.empty()) {
        if (surikiuoti.size() % 2 == 1)
            nd_mediana = surikiuoti[surikiuoti.size() / 2];
        else
            nd_mediana = (
                surikiuoti[surikiuoti.size() / 2 - 1] +
                surikiuoti[surikiuoti.size() / 2]
            ) / 2.0;
    }

    rez_med_ = 0.4 * nd_mediana + 0.6 * egz_;
}
