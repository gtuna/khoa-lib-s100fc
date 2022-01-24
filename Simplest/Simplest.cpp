#include "../FeatureCatalog/FeatureCatalogue.h"
#include <iostream>

int main()
{
    FeatureCatalogue fc;

    fc.Read(L"../SampleData/S-101_FC.xml");

    // Get a feature type
    auto featureDepthArea = fc.GetFeatureType(L"DepthArea");
    if (featureDepthArea)
    {
        // Retrieve attributes of a feature type
        auto attributeList = featureDepthArea->GetAttributeBindingPointer();
        for (auto i = attributeList.begin(); i != attributeList.end(); i++)
        {
            // Get a code of attribute
            std::wstring code = i->GetAttribute().GetReference();
        }
    }
    std::wcout << L"Hello S101-FC!\t" + fc.GetFilePath() + L"\n";


}
