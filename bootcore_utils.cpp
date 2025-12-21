
#include <string.h>

// Tests whether a filename is a dated release of a given core name.
//
// Parameters:
//   A - Generic core name (without date or extension), e.g. "NES"
//   B - Filename to test, e.g. "NES_20240115.rbf"
//
// Returns:
//   true if and only if B exactly matches the pattern
//     "<A>_YYYYMMDD.rbf"
//   where YYYYMMDD consists of exactly 8 decimal digits.
//   Returns false otherwise, including on NULL inputs.
bool matchesCore_yyyyMMdd_rbf(const char *A, const char *B)
{

    static const char *ext = ".rbf";

    if (!A || !B)
        return false;

    size_t a_len = strlen(A);
    size_t b_len = strlen(B);
    size_t ext_len = strlen(ext);

    // A + '_' + 8 digits + ".rbf"
    if (b_len != a_len + 1 + 8 + ext_len)
        return false;

    // Exact A prefix
    if (strncmp(B, A, a_len) != 0)
        return false;

    // Underscore
    if (B[a_len] != '_')
        return false;

    // Extension
    if (strcmp(B + b_len - ext_len, ext) != 0)
        return false;

    // 8 digits YYYYMMDD
    const char *digits = B + a_len + 1;
    for (int i = 0; i < 8; i++)
    {
        if (digits[i] < '0' || digits[i] > '9')
            return false;
    }

    return true;
}

bool preciseMatchOrGenericCoreName(const char *A, const char *B)
{
    if (!A || !B)
        return false;

    if (strcmp(A, B) == 0)
        return true;

    return matchesCore_yyyyMMdd_rbf(A, B);
}
