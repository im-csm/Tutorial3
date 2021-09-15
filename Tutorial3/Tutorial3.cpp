// Tutorial3.cpp 


#include "pch.h"
#include "framework.h"
#include "Tutorial3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

// The one and only application object

int main()
{
    winrt::init_apartment();

    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;
    SyndicationFeed syndicationFeed = syndicationClient.RetrieveFeedAsync(rssFeedUri).get();
    for (const SyndicationItem syndicationItem : syndicationFeed.Items())
    {
        winrt::hstring titleAsHstring = syndicationItem.Title().Text();
        std::wcout << titleAsHstring.c_str() << std::endl;
    }
}
