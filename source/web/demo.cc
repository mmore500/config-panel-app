//  This file is part of Config Panel App
//  Copyright (C) Matthew Andres Moreno, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>
#include <thread>
#include <chrono>

#include "web/web.h"
#include "web/Div.h"

#include "prefab/Card.h"
#include "prefab/CodeBlock.h"
#include "prefab/LoadingModal.h"

emp::web::Document doc("emp_base");

int main()
{
  // ----- Card ------- 
  // emp::prefab::Card static_card(emp::prefab::Card::Collapse::NONE, true, "STATIC");
  emp::prefab::Card static_card;
  doc << static_card;
  static_card.AddHeaderContent("<h2>Bootstrap Card</h2>");
  static_card.AddBodyContent("This will show up in the body of the card");

  emp::prefab::Card closed_card(emp::prefab::Card::Collapse::CLOSED, false, "CLOSED");
  doc << closed_card;
  closed_card.AddHeaderContent("<h2>Click to toggle open and close");
  emp::web::Div content;
  content << "<p>This content will appear and disappear!<p>";
  closed_card.AddBodyContent(content);

  // ----- CodeBlock ------- 
  std::string my_code = 
  R"(
    // Code for static card
    emp::prefab::Card static_card;
    doc << static_card;
    static_card.AddHeaderContent("&lth2&gtBootstrap Card&lt/h2&gt");
    static_card.AddBodyContent("This will show up in the body of the card");
  )";

  emp::prefab::CodeBlock code(my_code, "c++");
  doc << code;

  // Make sure modal shows
  std::this_thread::sleep_for(std::chrono::seconds{3});
  // Close the loading modal
  emp::prefab::CloseLoadingModal();

  std::cout << "end of main... !" << std::endl;
}
