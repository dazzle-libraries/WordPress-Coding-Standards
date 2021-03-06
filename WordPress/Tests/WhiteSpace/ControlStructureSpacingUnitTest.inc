<?php

// Bad, no space after opening control structure
while( have_posts() ) { // Okay, comments are okay here
	// Okay, comments are okay here as well
} // Okay, comments are okay here

// See https://github.com/WordPress-Coding-Standards/WordPress-Coding-Standards/issues/40
if ( true ) {

	// code
} else { //Are we allowed to comment here? If not, message is wrong
	// ...
}

// bad
if  ( 'update' === $option_operation['operation'] )
{
	update_option( $option_operation['option_name'], $option_operation['old_value'] );

}

// good
if ( 'update' === $option_operation['operation'] ) {
	update_option( $option_operation['option_name'], $option_operation['old_value'] );
}

// bad
if(true){}


if ( true ) {
    while ( false ) {

        echo 'OK';

    }

}

if ( false ):
else:
endif;

if ( false ) :
else :
endif;
// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 1
function($arg){} // Bad
function ( $arg ) {
	// OK
}

function () {
	// OK
}

function something($arg){} // Bad
function foo( $arg ) {
	// OK
}

function no_params() {
	// OK
}

function another () {} // Bad, space before open parenthesis prohibited.
function    and_another() {} // Bad, space before function name prohibited.
function
bar() {} // Bad
function baz()     {} // Bad
function test()
{} // Bad

function &return_by_ref() {} // OK

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 0

function() {} // OK
function( $arg ) {} // OK
function($arg){} // Bad
function () {} // Bad

$closureWithArgsAndVars = function( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // OK
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // Bad

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren 1

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // OK

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use( $var1, $var2 ) {}; // Bad, no space before open parenthesis prohibited.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use  ( $var1, $var2 ) {}; // Bad, expected exactly one space before opening parenthesis.

$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ){}; // Bad, space between closing parenthesis and control structure required.
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 )  {}; // Bad, expected exactly one space between closing parenthesis and control structure.

$closureWithArgsAndVars = function ( $arg1, $arg2 )use ( $var1, $var2 ) {}; // Bad, expected exactly one space between closing parenthesis and control structure.
$closureWithArgsAndVars = function ( $arg1, $arg2 )  use ( $var1, $var2 ) {}; // Bad, expected exactly one space between closing parenthesis and control structure.

// Namespaces.
use Foo\Admin;

// @codingStandardsChangeSetting WordPress.WhiteSpace.ControlStructureSpacing spaces_before_closure_open_paren -1

function( $arg ) {} // OK
function ( $arg ) {} // OK

$closureWithArgsAndVars = function( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // OK
$closureWithArgsAndVars = function ( $arg1, $arg2 ) use ( $var1, $var2 ) {}; // OK

/**
 * Test for bug where this sniff was triggering a "Blank line found after control structure" error
 * if there is a blank line after the last method in a class.
 *
 * Bug did not trigger when a comment was found after the closing brace of the method.
 *
 * Neither of the below examples should trigger the error.
 */
class Bar_Foo {

	function foo() {
	} // Now you won't see the bug.

}

class Foo_Bar {

	// Now you will.
	function bar() {
	}

}
