#include "InsertArrowsIntoString.h"

std::string InsertArrowsIntoString(const std::string& Text, Position Start, Position End)
{
    std::string Result = "";
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
        int ColumnStart = 0;
        if (i == 0)
        {
            ColumnStart = Start.GetColumnNumber();
        }
        int ColumnEnd = Line.length() - 1;
        if (i == LineCount)
        {
            ColumnEnd = End.GetColumnNumber();
        }
        Result += Line + "\n";
        Result += ' ' * ColumnEnd + '^' * (ColumnEnd - ColumnStart);
        IndexStart = IndexEnd;
        IndexEnd = Text.find("\n", IndexStart + 1);
        if (IndexEnd < 0)
        {
            IndexEnd = Text.length();
        }
    }
    return Result;
}
