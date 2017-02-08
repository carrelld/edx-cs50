//------------------------------------------------------------------------------
//
// Just a simple cheat sheet(program?) to help beginning programmers
// understand the following concepts
// - Passing an address to a pointer
// - Passing by reference
// - Passing by value
// - Scoping
// Written in C but I will write it in C++ as well.
// 
// Joshua Sanders
//

#include <stdio.h>
#include <string.h>

//==============================================================================
// Logging Stuff You Don't Need To Look At
//==============================================================================

void LogDebugMessage(char* message, const char* functionName)
{
	printf_s("%s | %s\n\n", message, functionName);
}

#define LOG_DEBUG_CONSOLE(msg)                                          \
{                                                                       \
	LogDebugMessage(msg, __FUNCTION__);          \
}

//==============================================================================
// End Logging Stuff You Don't Need To Look At
//==============================================================================

const char* g_speedAddressMsg = "Speed Address: %p, HP Address: %p";
const char* g_speedValueMsg = "Speed Value: %d, HP Value: %d";
const char* g_spacerMessage = "\n--------------------------------------------------------\n\n";
const char* g_pointerDereferencedValueMessage = "Speed Ptr's Value's value: %d, HP Ptr's Value's Value: %d";
const char* g_pointerValueMessage = "Speed Pointer's Value: %p, HP Pointer Value: %p";
const char* g_pointerAddressMessage = "Speed Pointer's Address: %p, HP Pointer's Address: %p";
char g_buffer[500];


// We pass an actual address by value here. This creates a local copy of two pointers
// speedAddress and hpAddress.
void PassAddressByValue(int* speedAddress, int* hpAddress)
{
	// This will print the address of the temporary local pointer itself.
	sprintf_s(g_buffer, g_pointerAddressMessage, &speedAddress, &hpAddress);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	// This will print the address that the pointer stores. Remember that the pointer's value IS an address.
	sprintf_s(g_buffer, g_pointerValueMessage, speedAddress, hpAddress);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	// *hpAddress means to dereference the hpAddress pointer. Its like saying, Hey pointer, you are pointing to
	// some data, give me the data that you are pointing to.

	*speedAddress = 75;
	*hpAddress = 1000;
	// To break it down, the pointer's value IS an address, so we look at that address and see the value
	// that is stored at that address. So this pointer points to an int address that holds the value of an int.
	// This is getting the value of that int.
	sprintf_s(g_buffer, g_pointerDereferencedValueMessage, *speedAddress, *hpAddress);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

} // The local speedAddress pointer and hpAddress pointer are destroyed here.

  // Takes a reference to speed and hp. This does not mean that the value of speed is its address.
  // You cannot take the address of a reference. Though it has its own space on the stack, the address is not visible to you.
  // A reference kind of acts like an alias to the data you assign it to, and its more efficient to pass around than a
  // copy of the object.
void PassByReference(int& speed, int& hp)
{
	// Print the value of speed and hp.
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	// Setting the values very specifically to the speed and hp passed in from the caller (main in this case).
	// It does this by using the reference passed in to modify the values at main::speed and main::hp.
	speed = 10;
	hp = 20;

	// Print the address of speed and hp.
	sprintf_s(g_buffer, g_speedAddressMsg, (void*)&speed, (void*)&hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);
}// Neither speed, or hp are destroyed here as their lifetime is managed outside of this scope.

 // Creates a copy of speed and hp, and stores them into a different address on the stack.
void PassByValue(int speed, int hp)
{
	// Setting the values to the speed copy.
	speed = 10;
	hp = 20;

	// Print the value of speed and hp.
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	// Print the address of speed and hp.
	sprintf_s(g_buffer, g_speedAddressMsg, (void*)&speed, (void*)&hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);
} // Leaving scope, the copy of speed and hp are destroyed here.

int main()
{
	// It is important to note that ALL memory created in this program
	// is created on the stack. There is no dynamic heap allocated memory in this program. 

	// Initialize.
	int speed = 0;
	int hp = 0;
	memset(g_buffer, ' ', 500);

	// Store message into buffer
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	// Actually log the message to the console.
	LOG_DEBUG_CONSOLE(g_buffer);
	// Clear the buffer.
	memset(g_buffer, ' ', 500);

	// Print the address of speed and hp.
	sprintf_s(g_buffer, g_speedAddressMsg, (void*)&speed, (void*)&hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	//--------------------------------------------------------------
	printf(g_spacerMessage);

	// What happens when we pass by value?
	PassByValue(speed, hp);

	// Print the value of speed and hp.
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	//--------------------------------------------------------------
	printf(g_spacerMessage);

	// What happens when we pass by reference?
	PassByReference(speed, hp);

	// Print the value of speed and hp.
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);


	///////////////////////////////////////////////////////////////////////////
	// Bonus - This explains what was asked about passing an actual address in.
	///////////////////////////////////////////////////////////////////////////
	printf(g_spacerMessage);

	// Change the values of speed and hp.
	speed = 7;
	hp = 9;

	// A pointer is a data type that stores an address. Therefore, the value of a pointer, IS an address.
	// The address that a pointer points to does NOT have to be valid and as such is not guaranteed to be.

	// This is actually passing the address of speed and hp.
	PassAddressByValue(&speed, &hp);

	// Print the value of speed and hp.
	sprintf_s(g_buffer, g_speedValueMsg, speed, hp);
	LOG_DEBUG_CONSOLE(g_buffer);
	memset(g_buffer, ' ', 500);

	//---------------------------------------------------------------------
	// Further notes: answers the question about int& speed getting a literal address
	// and whether or not that would be bad
	//---------------------------------------------------------------------

	// The following code will NOT compile.
	// PassByReference(3, 4);

	// The reason it will not compile is that PassByReference takes a reference to an rValue. An rValue is
	// essentially a value which can be assigned to, so it already has a place in memory. '3' is an lValue,
	// often called a 'literal' value. It has no address on the stack that is referenceable from anywhere
	// in the program.

	// It is enforced by the compiler that references (int&) cannot be NULL and MUST have a valid address.
	// This provides a guarantee that all references are safe to operate on.

	//---------------------------------------------------------------------
	// A note on efficiency
	//---------------------------------------------------------------------

	// All pointers are 4 bytes. No matter how big the object that they point to is.
	// This is why if you have a million objects of size 200bytes, it is way more efficient
	// to pass pointers-to-that-object to functions, and not the objects themselves.

	// A reference is always a stack variable though it can point to things on the stack or from the heap.
	// It also takes up a bit more space than a pointer, it has its own section on the stack. Because it
	// MUST have a value at initialization time, it kind of acts like an 'alias' for the value you give it.
	// You cannot take the address of a reference.
	
	
	//---------------------------------------------------------------------
	// A note on syntax
	//---------------------------------------------------------------------

	// The * and & operators do differnt things depending on the context.
	
	// int* intPtr creates a pointer to a piece of memory that has an int value.
	// *intPtr dereferences the pointer to return the int value of the address it points to.

	// int& intRef creates a reference to an int and must have a value at initialization time.

	// int myInt = 0;
	// int address = &myInt; store the physical address of myInt into the address value.
	return 0;
}