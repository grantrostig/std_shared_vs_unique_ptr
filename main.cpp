#include <bits/stdc++.h>
using namespace std;

struct Common_resource {
  int       my_int {99};
  string    my_string;
};

using Common_resource_sp = std::shared_ptr<Common_resource>;
using Common_resource_up = std::unique_ptr<Common_resource>;

void Resource_user1_fn( Common_resource_up   cr ) {  // todo??: try by ref and const
  cr->my_int = 42;
}

void Resource_user2_fn( Common_resource_up   cr ) { cr->my_int = 43; }
void Resource_user3_fn( Common_resource_up & cr ) { cr->my_int = 44; }
void Resource_user4_fn( Common_resource_up & cr ) { cr->my_int = 44; }
int  Resource_user1_fn( Common_resource_sp   cr ) { return cr->my_int = 42; }
int  Resource_user2_fn( Common_resource_sp   cr ) { return cr->my_int = 43; }

int main() {
  std::shared_ptr< Common_resource > common_resource_sp1 = std::shared_ptr< Common_resource > ( new Common_resource {} );
  std::shared_ptr< Common_resource > common_resource_sp2 { std::shared_ptr< Common_resource > ( new Common_resource {} )};
  std::shared_ptr< Common_resource > common_resource_sp3 { new Common_resource {} };  // todo??: why are {} in italics?
  std::shared_ptr< Common_resource > common_resource_sp5 { new Common_resource {} };  // todo??: why are {} in italics?
  auto                               common_resource_sp6 = std::shared_ptr< Common_resource > ( new Common_resource {} );
  auto                               common_resource_sp7 { std::shared_ptr< Common_resource > ( new Common_resource {} )};
  auto                               common_resource_sp8 { std::shared_ptr< Common_resource > ( new Common_resource {} )};
  auto                               common_resource_sp9 { new Common_resource {} };

  Common_resource_sp common_resource_sp      { new Common_resource {} };
  Common_resource_sp common_resource_sp_copy { common_resource_sp };
  cout << "sp1: "<<Resource_user1_fn( common_resource_sp );
  common_resource_sp->my_int = 98;
  Resource_user1_fn( common_resource_sp );
  cout << "sp2: "<<Resource_user2_fn( common_resource_sp );

  Common_resource_up common_resource_up      { new Common_resource {} };
  //Common_resource_sp common_resource_up_copy { common_resource_up };
  common_resource_up_copy = common_resource_up;

  //Resource_user1_fn( common_resource_up );
  //Resource_user2_fn( common_resource_up );
  Resource_user3_fn( common_resource_up );
  Resource_user3_fn( common_resource_up );
  Resource_user4_fn( common_resource_up );

  cout << "###" << endl;
  return 0;
}
