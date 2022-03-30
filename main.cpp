#include <bits/stdc++.h>
using namespace std;

struct Common_resource {
  int       my_int;
  string    my_string;
};

using Buff_p                = uint8_t *;
using Buff_p_same           = uint8_t[];    // todo??: is this really the same, apparently not, but it decays to a pointer?
using Buff_sp               = std::shared_ptr< uint8_t[1024] >;
using Buff_sp_open          = std::shared_ptr< uint8_t[] >;
using Buff_sp_uint8         = std::shared_ptr< uint8_t >;
using Buff_sp_to_ptr        = std::shared_ptr< Buff_p >;  // todo??: how crazy it that?
using Buff_sp_same_to_ptr   = std::shared_ptr< Buff_p_same >;  // todo??: how crazy it that?

using Common_resource_sp    = std::shared_ptr<Common_resource>;
using Common_resource_up    = std::unique_ptr<Common_resource>;

void Resource_user1_fn( Common_resource_up   cr ) { cr->my_int = 42; }// todo??: try by ref and const
void Resource_user2_fn( Common_resource_up   cr ) { cr->my_int = 43; }
void Resource_user3_fn( Common_resource_up & cr ) { cr->my_int = 44; }
void Resource_user4_fn( Common_resource_up & cr ) { cr->my_int = 45; }
// shared_ptr overloads
int  Resource_user1_fn( Common_resource_sp   cr ) { return cr->my_int = 42; }
int  Resource_user2_fn( Common_resource_sp   cr ) { return cr->my_int = 43; }

int main() {
  u_int8_t              buff[1024]                      { 99 };  // to fill it: https://stackoverflow.com/questions/69009464/populating-a-buffer-in-c
  u_int8_t              buff2[]                         { 99,98,97,0 };  // to fill it: https://stackoverflow.com/questions/69009464/populating-a-buffer-in-c
  Buff_p                buff_p                          { new uint8_t[1024] {99} } ;
                                                            cout << sizeof(buff) << "," << sizeof(buff_p) <<"," << buff2 << endl;
  // make a sp to the buffer, not the pointer.
  shared_ptr<uint8_t[]> buff_sp1                        { shared_ptr<uint8_t []> {new uint8_t[1024]}};
  unique_ptr<uint8_t[]> buff_up1                        { unique_ptr<uint8_t []> {new uint8_t[1024]}};
  //shared_ptr<uint8_t[]> buff_sp4                        { make_shared<uint8_t []>(1024) };
  unique_ptr<uint8_t[]> buff_up4                        { make_unique<uint8_t []>(1024) };
  //auto                  buff_sp2                        { make_shared<uint8_t [1024]> }; // todo??: shared_ptr<uint8_t[1024]> *() buff_sp3                        { make_shared<uint8_t [1024]> };
  //Buff_sp_same_to_ptr   buff_sp2                        { shared_ptr<Buff_p_same> {new Buff_p_same}};  // todo??: is this a pointer to a pointer?
  //auto                  junk { new uint8_t (1024)};
  //shared_ptr<uint8_t *> buff_sp5                        { shared_ptr<uint8_t *> {(u_int8_t *)new uint8_t (1024)}};
  //Buff_sp_to_ptr        buff_sp3                        { shared_ptr<Buff_p> {new Buff_p}};  // todo??: is this a pointer to a pointer?
  //shared_ptr<u_int8_t>  buff_sp4                        { shared_ptr<uint8_t > {new uint8_t}};
  //shared_ptr<u_int8_t>  buff_sp3                        { buff_p};  // todo: works because of type deduction?

  //Buff_sp               buff_sp                         { make_shared< uint8_t[1024]>() };  //todo:?? not allowed via static assert in lib.
  //Buff_sp_open          buff_sp_open                    { make_shared< uint8_t[]>() };  //todo:?? not allowed via static assert in lib.

  u_int8_t              archive[1024*1024]              { 98 };  // to fill it: https://stackoverflow.com/questions/69009464/populating-a-buffer-in-c
  /* //Common_resource       common_resource                 { 99,"str" };

  //Common_resource_up    common_resource_up1             { new Common_resource {99,"str"} };
  //Common_resource_up    common_resource_up_copy1up1     { common_resource_up1.get() };
  //Common_resource_up    common_resource_up_copy2up1     { std::move( common_resource_up1.get()) };  // todo??: is this pessimized?
  //Common_resource_up    common_resource_up_copy3up1   = std::move( common_resource_up1.get() );  // todo??:

  //Common_resource_sp    common_resource_sp_copyup1b    = common_resource_up1.get();  // can't copy
  //Common_resource_sp    common_resource_sp_copyup1c    = std::move( common_resource_up1.get() );  // todo??: why? not just copy problem?
  //Common_resource_sp    common_resource_sp_copy2up1     { common_resource_up1.get() };  // todo??: Is this a ????
  //Common_resource *     common_resource_sp_copy1up1     { common_resource_up1.get() };

  //common_resource_sp_copyup1 = common_resource_up1.get();  // can't copy assign
  //common_resource_sp_copyup1 = std::move( common_resource_up1.get());  // todo??: why? not just copy assign problem?

  //Resource_user1_fn( common_resource_up1 );  // can't copy
  //Resource_user2_fn( common_resource_up1 );  // can't copy
  //Resource_user1_fn( std::move(common_resource_up1) );
  //Resource_user2_fn( std::move(common_resource_up1) );  // todo??: get a warning, but not a compile error, and DO get a crash, but not a runtime error/exception?

  //uResource_user3_fn( common_resource_up1 );  // crashes.
  //Resource_user4_fn( common_resource_up1 );  // todo??: why does this compile, I now have two owners in the two functions, maybe three with the local up?  // crashes too?

  //Common_resource_sp    common_resource_sp2 { Common_resource_sp ( new Common_resource {} )};
  //Common_resource_sp    common_resource_sp3 { new Common_resource {} };  // todo: why are {} in italics sometimes?? slowly show up??
  //Common_resource_sp    common_resource_sp1 = Common_resource_sp ( new Common_resource {} );
  //auto                  common_resource_sp6 = Common_resource_sp ( new Common_resource {} );
  //auto                  common_resource_sp7 { Common_resource_sp ( new Common_resource {} )};
  //auto                  common_resource_sp9 { new Common_resource {} };  // just a regular pointer

  //Common_resource_sp    common_resource_spA { make_shared< Common_resource >()};
  //Common_resource_sp    common_resource_spB = make_shared< Common_resource >();

  //Common_resource_sp common_resource_sp      { new Common_resource {} };
  //Common_resource_sp common_resource_sp_copy { common_resource_sp };
  //cout << "sp1: "<<Resource_user1_fn( common_resource_sp )<<endl;
  //common_resource_sp->my_int = 98;
  //Resource_user1_fn( common_resource_sp );
  //cout << "sp2: "<<Resource_user2_fn( common_resource_sp )<<endl;
  */

  int * array_int_ptr[] { new int(100), new int(200) };
  //vector<int*> vec_int_ptr1 { make_move_iterator(begin(array_int_ptr)), make_move_iterator(end(array_int_ptr)) };  // todo??: what is make_move_iterator?
  //vector<int*> vec_int_ptr2 { begin(array_int_ptr), end(array_int_ptr) };  // todo??: what is make_move_iterator?

  unique_ptr<int> array_unique[] { std::make_unique<int>(100), std::make_unique<int>(200) };
  vector<unique_ptr<int>> vec_int_uptr1 { make_move_iterator(begin(array_unique)), make_move_iterator(end(array_unique)) };  // todo??: what is make_move_iterator?

  shared_ptr<int> array_shared[] { std::make_shared<int>(100), std::make_shared<int>(200) };
  vector<shared_ptr<int>> vec_int_sptr1 { make_move_iterator(begin(array_shared)), make_move_iterator(end(array_shared)) };  // todo??: what is make_move_iterator?
  vector<shared_ptr<int>> vec_int_sptr2 { begin(array_shared), end(array_shared) };  // todo??: don't need make_move_iterator

  cout << "###" << endl;
  return 0;
}
