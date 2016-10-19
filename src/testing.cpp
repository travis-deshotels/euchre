#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

int main( int argc, char* argv[] )
{
  CPPUNIT_NS::TextUi::TestRunner runner;

  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

  return runner.run() ? 0 : 1;	// return 0 if test succeeds, 1 if test fails
}
