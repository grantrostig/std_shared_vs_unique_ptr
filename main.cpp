#include <bits/stdc++.h>
using namespace std;

struct Common_resource {
  int       my_int {99};
  string    my_string;
};
using Common_resource_sp = std::shared_ptr<Common_resource>;
using Common_resource_up = std::unique_ptr<Common_resource>;

void Resource_user1_fn( Common_resource_up   cr ) { cr->my_int = 42; }// todo??: try by ref and const
void Resource_user2_fn( Common_resource_up   cr ) { cr->my_int = 43; }
void Resource_user3_fn( Common_resource_up & cr ) { cr->my_int = 44; }
void Resource_user4_fn( Common_resource_up & cr ) { cr->my_int = 45; }

int  Resource_user1_fn( Common_resource_sp   cr ) { return cr->my_int = 42; }
int  Resource_user2_fn( Common_resource_sp   cr ) { return cr->my_int = 43; }

int main() {
  Common_resource_up    common_resource_up1             { new Common_resource {} };
  Common_resource_up    common_resource_up_copy1up1     { common_resource_up1.get() };
  Common_resource_up    common_resource_up_copy2up1     { std::move( common_resource_up1.get()) };  // todo??: is this pessimized?
  //Common_resource_up    common_resource_up_copy3up1   = std::move( common_resource_up1.get() );  // todo??:

  //Common_resource_sp    common_resource_sp_copyup1b    = common_resource_up1.get();  // can't copy
  //Common_resource_sp    common_resource_sp_copyup1c    = std::move( common_resource_up1.get() );  // todo??: why? not just copy problem?
  Common_resource_sp    common_resource_sp_copy2up1     { common_resource_up1.get() };  // todo??: Is this a ????
  Common_resource *     common_resource_sp_copy1up1     { common_resource_up1.get() };

  //common_resource_sp_copyup1 = common_resource_up1.get();  // can't copy assign
  //common_resource_sp_copyup1 = std::move( common_resource_up1.get());  // todo??: why? not just copy assign problem?

  //Resource_user1_fn( common_resource_up1 );  // can't copy
  //Resource_user2_fn( common_resource_up1 );  // can't copy
  Resource_user1_fn( std::move(common_resource_up1) );
  //Resource_user2_fn( std::move(common_resource_up1) );  // todo??: get a warning, but not a compile error, and DO get a crash, but not a runtime error/exception?

  //uResource_user3_fn( common_resource_up1 );  // crashes.
  //Resource_user4_fn( common_resource_up1 );  // todo??: why does this compile, I now have two owners in the two functions, maybe three with the local up?  // crashes too?

  Common_resource_sp    common_resource_sp1 = Common_resource_sp ( new Common_resource {} );
  Common_resource_sp    common_resource_sp2 { Common_resource_sp ( new Common_resource {} )};
  Common_resource_sp    common_resource_sp3 { new Common_resource {} };  // todo: why are {} in italics sometimes?? slowly show up??
  auto                  common_resource_sp6 = Common_resource_sp ( new Common_resource {} );
  auto                  common_resource_sp7 { Common_resource_sp ( new Common_resource {} )};
  auto                  common_resource_sp9 { new Common_resource {} };  // just a regular pointer

  Common_resource_sp common_resource_sp      { new Common_resource {} };
  Common_resource_sp common_resource_sp_copy { common_resource_sp };
  cout << "sp1: "<<Resource_user1_fn( common_resource_sp );
  common_resource_sp->my_int = 98;
  Resource_user1_fn( common_resource_sp );
  cout << "sp2: "<<Resource_user2_fn( common_resource_sp );

  cout << "###" << endl;
  return 0;
}
