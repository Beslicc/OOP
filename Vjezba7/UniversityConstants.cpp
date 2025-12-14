#include "UniversityConstants.h"

const int UniversityConstants::MAX_ETCS_PER_YEAR = 60;
const int UniversityConstants::REQUIRED_ECTS_PER_YEAR = 45;

void UniversityConstants::print_university_rules() {
    std::cout << "University Rules:\n";
    std::cout << "MAX ECTS per year: " << MAX_ETCS_PER_YEAR << "\n";
    std::cout << "REQUIRED ECTS per year: " << REQUIRED_ECTS_PER_YEAR << "\n";
}