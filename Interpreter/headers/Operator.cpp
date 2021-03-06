#include "Operator.h"

std::ostream& operator<<(std::ostream& os, const Operator& op)
{
    os << op.GetOperatorName();
    return os;
}
