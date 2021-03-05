#include "InsertArrowsIntoString.h"

std::string InsertArrowsIntoString(const std::string& Text, Position Start, Position End)
{
    int IndexStart = std::max((int)Text.rfind("\n", 0, Start.GetIndex()), 0);
    int IndexEnd = Text.find('\n', IndexStart + 1);
    if (IndexEnd < 0)
    {
        IndexEnd = (int)Text.length();
    }

    int LineCount = End.GetLineNumber() - Start.GetLineNumber() + 1;
    for (int i = 0; i < LineCount; i++)
    {
        std::string Line = Text.substr(IndexStart, IndexEnd);
    }
    return std::string(0);
}
