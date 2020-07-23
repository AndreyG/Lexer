#pragma once

#include "TokenNodeType.h"

ref struct CppTokenNodeType : TokenNodeType
{
    CppTokenNodeType(String^ s)
    { }
};

ref struct CppTokenNodeTypes sealed
{

#define TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define DIRECTIVE_TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define COMMENT_TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define DOXYGEN_COMMENT_TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define KEYWORD_TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define PUNCTUATOR_TOKEN_NODE_TYPE(NAME, TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)

#define PUNCTUATOR_ALT_TOKEN_NODE_TYPE(NAME, TEXT, ALT_TEXT) \
    static initonly CppTokenNodeType^ NAME = gcnew CppTokenNodeType(#NAME)


    TOKEN_NODE_TYPE(UNKNOWN_TOKEN,            "@unknown");
    TOKEN_NODE_TYPE(CLOSED_CHAMELEON_TOKEN,   "@closed_chameleon");

    TOKEN_NODE_TYPE(IDENTIFIER,                   "sample_ident");
    TOKEN_NODE_TYPE(EXPAND_DISABLED_IDENTIFIER,   "sample_ident");
    TOKEN_NODE_TYPE(HASHED_IDENTIFIER,            "#sample_ident");
    TOKEN_NODE_TYPE(DIRECTIVE_CONTENT,            "#directive_content");
    TOKEN_NODE_TYPE(CODE_DIRECTIVE_CONTENT,       "#code_directive_content");
    TOKEN_NODE_TYPE(INCLUDE_DIRECTIVE_CONTENT,    "#include_directive_content");
    TOKEN_NODE_TYPE(END_OF_DIRECTIVE_CONTENT,     "");

    DIRECTIVE_TOKEN_NODE_TYPE(IF_DIRECTIVE,       "#if");
    DIRECTIVE_TOKEN_NODE_TYPE(IFDEF_DIRECTIVE,    "#ifdef");
    DIRECTIVE_TOKEN_NODE_TYPE(IFNDEF_DIRECTIVE,   "#ifndef");
    DIRECTIVE_TOKEN_NODE_TYPE(ELIF_DIRECTIVE,     "#elif");
    DIRECTIVE_TOKEN_NODE_TYPE(ELSE_DIRECTIVE,     "#else");
    DIRECTIVE_TOKEN_NODE_TYPE(ENDIF_DIRECTIVE,    "#endif");
  
    DIRECTIVE_TOKEN_NODE_TYPE(INCLUDE_DIRECTIVE,  "#include");
    DIRECTIVE_TOKEN_NODE_TYPE(INCLUDE_NEXT_DIRECTIVE, "#include_next");
    DIRECTIVE_TOKEN_NODE_TYPE(IMPORT_DIRECTIVE,   "#import");
    DIRECTIVE_TOKEN_NODE_TYPE(DEFINE_DIRECTIVE,   "#define");
    DIRECTIVE_TOKEN_NODE_TYPE(UNDEF_DIRECTIVE,    "#undef");
    DIRECTIVE_TOKEN_NODE_TYPE(LINE_DIRECTIVE,     "#line");
    DIRECTIVE_TOKEN_NODE_TYPE(ERROR_DIRECTIVE,    "#error");
    DIRECTIVE_TOKEN_NODE_TYPE(WARNING_DIRECTIVE,  "#warning");
    DIRECTIVE_TOKEN_NODE_TYPE(PRAGMA_DIRECTIVE,   "#pragma");
  
    TOKEN_NODE_TYPE(EMPTY_DIRECTIVE,      "#");
    TOKEN_NODE_TYPE(UNKNOWN_DIRECTIVE,    "#unknown");

    TOKEN_NODE_TYPE(EOL_ESCAPE,   "\\");
    TOKEN_NODE_TYPE(WHITE_SPACE,  " ");
    TOKEN_NODE_TYPE(NEW_LINE,     System::Environment::NewLine);

    TOKEN_NODE_TYPE(NUMERIC_LITERAL,      "0");
    TOKEN_NODE_TYPE(CHARACTER_LITERAL,    "'a'");
    TOKEN_NODE_TYPE(STRING_LITERAL,       "\"\"");

    TOKEN_NODE_TYPE(FAKE_TRUE,    "@true");
    TOKEN_NODE_TYPE(FAKE_FALSE,   "@false");

    TOKEN_NODE_TYPE(RETRY, "@retry");

    //
    // Doxygen comments
    //
    DOXYGEN_COMMENT_TOKEN_NODE_TYPE(DOXYGEN_EOL_COMMENT_PREFIX, "/// or //!");
    DOXYGEN_COMMENT_TOKEN_NODE_TYPE(DOXYGEN_MULTILINE_COMMENT_PREFIX, "/** or /*!");
    DOXYGEN_COMMENT_TOKEN_NODE_TYPE(DOXYGEN_MULTILINE_COMMENT_POSTFIX, "*/");
    DOXYGEN_COMMENT_TOKEN_NODE_TYPE(DOXYGEN_QUOTE, "\\\" or @\"");

    PUNCTUATOR_TOKEN_NODE_TYPE(AT, "@");



    //
    // Comments
    //

    COMMENT_TOKEN_NODE_TYPE(BLOCK_COMMENT,            "/*comment*/");
    COMMENT_TOKEN_NODE_TYPE(UNFINISHED_BLOCK_COMMENT, "/*comment");
    COMMENT_TOKEN_NODE_TYPE(GENERATED_COMMENT,        "//comment");
    COMMENT_TOKEN_NODE_TYPE(EOL_COMMENT,              "//comment");
    COMMENT_TOKEN_NODE_TYPE(DOXYGEN_EOL_COMMENT_BLOCK,"///comment<endl>///comment");
  
    TOKEN_NODE_TYPE(CONDITIONALLY_NOT_COMPILED_CODE,  "@conditionally_not_compiled");
    static initonly TokenNodeType^ MODIFICATION_UTIL_MARKER = CONDITIONALLY_NOT_COMPILED_CODE;

    //   
    // C99 keywords
    //

    KEYWORD_TOKEN_NODE_TYPE(AUTO_KEYWORD,     "auto");
    KEYWORD_TOKEN_NODE_TYPE(BREAK_KEYWORD,    "break");
    KEYWORD_TOKEN_NODE_TYPE(CASE_KEYWORD,     "case");
    KEYWORD_TOKEN_NODE_TYPE(CHAR_KEYWORD,     "char");
    KEYWORD_TOKEN_NODE_TYPE(CONST_KEYWORD,    "const");
    KEYWORD_TOKEN_NODE_TYPE(CONTINUE_KEYWORD, "continue");
    KEYWORD_TOKEN_NODE_TYPE(DEFAULT_KEYWORD,  "default");
    KEYWORD_TOKEN_NODE_TYPE(DO_KEYWORD,       "do");
    KEYWORD_TOKEN_NODE_TYPE(DOUBLE_KEYWORD,   "double");
    KEYWORD_TOKEN_NODE_TYPE(ELSE_KEYWORD,     "else");
    KEYWORD_TOKEN_NODE_TYPE(ENUM_KEYWORD,     "enum");
    KEYWORD_TOKEN_NODE_TYPE(EXTERN_KEYWORD,   "extern");
    KEYWORD_TOKEN_NODE_TYPE(FLOAT_KEYWORD,    "float");
    KEYWORD_TOKEN_NODE_TYPE(FOR_KEYWORD,      "for");
    KEYWORD_TOKEN_NODE_TYPE(GOTO_KEYWORD,     "goto");
    KEYWORD_TOKEN_NODE_TYPE(IF_KEYWORD,       "if");
    KEYWORD_TOKEN_NODE_TYPE(INLINE_KEYWORD,   "inline");
    KEYWORD_TOKEN_NODE_TYPE(INT_KEYWORD,      "int");
    KEYWORD_TOKEN_NODE_TYPE(LONG_KEYWORD,     "long");
    KEYWORD_TOKEN_NODE_TYPE(REGISTER_KEYWORD, "register");
    KEYWORD_TOKEN_NODE_TYPE(RETURN_KEYWORD,   "return");
    KEYWORD_TOKEN_NODE_TYPE(SHORT_KEYWORD,    "short");
    KEYWORD_TOKEN_NODE_TYPE(SIGNED_KEYWORD,   "signed");
    KEYWORD_TOKEN_NODE_TYPE(SIZEOF_KEYWORD,   "sizeof");
    KEYWORD_TOKEN_NODE_TYPE(STATIC_KEYWORD,   "static");
    KEYWORD_TOKEN_NODE_TYPE(STRUCT_KEYWORD,   "struct");
    KEYWORD_TOKEN_NODE_TYPE(SWITCH_KEYWORD,   "switch");
    KEYWORD_TOKEN_NODE_TYPE(TYPEDEF_KEYWORD,  "typedef");
    KEYWORD_TOKEN_NODE_TYPE(UNION_KEYWORD,    "union");
    KEYWORD_TOKEN_NODE_TYPE(UNSIGNED_KEYWORD, "unsigned");
    KEYWORD_TOKEN_NODE_TYPE(VOID_KEYWORD,     "void");
    KEYWORD_TOKEN_NODE_TYPE(VOLATILE_KEYWORD, "volatile");
    KEYWORD_TOKEN_NODE_TYPE(WHILE_KEYWORD,    "while");

    //
    // C11 Keywords
    //
    KEYWORD_TOKEN_NODE_TYPE(C11_ALIGNAS_KEYWORD, "_Alignas");
    KEYWORD_TOKEN_NODE_TYPE(C11_ALIGNOF_KEYWORD, "_Alignof");
    KEYWORD_TOKEN_NODE_TYPE(C11_ATOMIC_KEYWORD, "_Atomic");
    KEYWORD_TOKEN_NODE_TYPE(C11_BOOL_KEYWORD, "_Bool");
    KEYWORD_TOKEN_NODE_TYPE(C11_COMPLEX_KEYWORD, "_Complex");
    KEYWORD_TOKEN_NODE_TYPE(C11_GENERIC_KEYWORD, "_Generic");
    KEYWORD_TOKEN_NODE_TYPE(C11_IMAGINARY_KEYWORD, "_Imaginary");
    KEYWORD_TOKEN_NODE_TYPE(C11_NORETURN_KEYWORD, "_Noreturn");
    KEYWORD_TOKEN_NODE_TYPE(C11_STATIC_ASSERT_KEYWORD, "_Static_assert");
    KEYWORD_TOKEN_NODE_TYPE(C11_THREAD_LOCAL_KEYWORD, "_Thread_local");

    //
    // C++ 2.11p1: Keywords.
    //

    KEYWORD_TOKEN_NODE_TYPE(ASM_KEYWORD,            "asm");
    KEYWORD_TOKEN_NODE_TYPE(BOOL_KEYWORD,             "bool");
    KEYWORD_TOKEN_NODE_TYPE(CATCH_KEYWORD,            "catch");
    KEYWORD_TOKEN_NODE_TYPE(CLASS_KEYWORD,            "class");
    KEYWORD_TOKEN_NODE_TYPE(CONST_CAST_KEYWORD,       "const_cast");
    KEYWORD_TOKEN_NODE_TYPE(DELETE_KEYWORD,           "delete");
    KEYWORD_TOKEN_NODE_TYPE(DYNAMIC_CAST_KEYWORD,     "dynamic_cast");
    KEYWORD_TOKEN_NODE_TYPE(EXPLICIT_KEYWORD,         "explicit");
    KEYWORD_TOKEN_NODE_TYPE(EXPORT_KEYWORD,           "export");
    KEYWORD_TOKEN_NODE_TYPE(FALSE_KEYWORD,            "false");
    KEYWORD_TOKEN_NODE_TYPE(FRIEND_KEYWORD,           "friend");
    KEYWORD_TOKEN_NODE_TYPE(MUTABLE_KEYWORD,          "mutable");
    KEYWORD_TOKEN_NODE_TYPE(NAMESPACE_KEYWORD,        "namespace");
    KEYWORD_TOKEN_NODE_TYPE(NEW_KEYWORD,              "new");
    KEYWORD_TOKEN_NODE_TYPE(OPERATOR_KEYWORD,         "operator");
    KEYWORD_TOKEN_NODE_TYPE(PRIVATE_KEYWORD,          "private");
    KEYWORD_TOKEN_NODE_TYPE(PUBLIC_KEYWORD,           "public");
    KEYWORD_TOKEN_NODE_TYPE(PROTECTED_KEYWORD,        "protected");
    KEYWORD_TOKEN_NODE_TYPE(REINTERPRET_CAST_KEYWORD, "reinterpret_cast");
    KEYWORD_TOKEN_NODE_TYPE(STATIC_CAST_KEYWORD,      "static_cast");
    KEYWORD_TOKEN_NODE_TYPE(TEMPLATE_KEYWORD,         "template");
    KEYWORD_TOKEN_NODE_TYPE(THIS_KEYWORD,             "this");
    KEYWORD_TOKEN_NODE_TYPE(THROW_KEYWORD,            "throw");
    KEYWORD_TOKEN_NODE_TYPE(TRUE_KEYWORD,             "true");
    KEYWORD_TOKEN_NODE_TYPE(TRY_KEYWORD,              "try");
    KEYWORD_TOKEN_NODE_TYPE(TYPENAME_KEYWORD,         "typename");
    KEYWORD_TOKEN_NODE_TYPE(TYPEID_KEYWORD,           "typeid");
    KEYWORD_TOKEN_NODE_TYPE(USING_KEYWORD,            "using");
    KEYWORD_TOKEN_NODE_TYPE(VIRTUAL_KEYWORD,          "virtual");
    KEYWORD_TOKEN_NODE_TYPE(WCHAR_T_KEYWORD,          "wchar_t");

    //
    // C++ 2.5p2: Alternative Representations.
    //

    //CXX_KEYWORD_OPERATOR(and     , ampamp)
    //CXX_KEYWORD_OPERATOR(and_eq  , ampequal)
    //CXX_KEYWORD_OPERATOR(bitand  , amp)
    //CXX_KEYWORD_OPERATOR(bitor   , pipe)
    //CXX_KEYWORD_OPERATOR(compl   , tilde)
    //CXX_KEYWORD_OPERATOR(not     , exclaim)
    //CXX_KEYWORD_OPERATOR(not_eq  , exclaimequal)
    //CXX_KEYWORD_OPERATOR(or      , pipepipe)
    //CXX_KEYWORD_OPERATOR(or_eq   , pipeequal)
    //CXX_KEYWORD_OPERATOR(xor     , caret)
    //CXX_KEYWORD_OPERATOR(xor_eq  , caretequal)

    //
    // C++0x keywords
    //

    KEYWORD_TOKEN_NODE_TYPE(__FUNCTION__KEYWORD,    "__FUNCTION__");
    KEYWORD_TOKEN_NODE_TYPE(__FUNCSIG__KEYWORD,     "__FUNCSIG__");
    KEYWORD_TOKEN_NODE_TYPE(__FUNCDNAME__KEYWORD,   "__FUNCDNAME__");
    KEYWORD_TOKEN_NODE_TYPE(ALIGNAS_KEYWORD,        "alignas");
    KEYWORD_TOKEN_NODE_TYPE(ALIGNOF_KEYWORD,        "alignof");
    KEYWORD_TOKEN_NODE_TYPE(CHAR8_T_KEYWORD,        "char8_t");
    KEYWORD_TOKEN_NODE_TYPE(CHAR16_T_KEYWORD,       "char16_t");
    KEYWORD_TOKEN_NODE_TYPE(CHAR32_T_KEYWORD,       "char32_t");
    KEYWORD_TOKEN_NODE_TYPE(CONSTEXPR_KEYWORD,      "constexpr");
    KEYWORD_TOKEN_NODE_TYPE(CONSTEVAL_KEYWORD,      "consteval");
    KEYWORD_TOKEN_NODE_TYPE(CONSTINIT_KEYWORD,      "constinit");
    KEYWORD_TOKEN_NODE_TYPE(DECLTYPE_KEYWORD,       "decltype");
    KEYWORD_TOKEN_NODE_TYPE(NOEXCEPT_KEYWORD,       "noexcept");
    KEYWORD_TOKEN_NODE_TYPE(NULLPTR_KEYWORD,        "nullptr");
    KEYWORD_TOKEN_NODE_TYPE(STATIC_ASSERT_KEYWORD,  "static_assert");
    KEYWORD_TOKEN_NODE_TYPE(THREAD_LOCAL_KEYWORD,   "thread_local");

    KEYWORD_TOKEN_NODE_TYPE(FINAL_KEYWORD,          "final");
    KEYWORD_TOKEN_NODE_TYPE(OVERRIDE_KEYWORD,       "override");

    //
    // C++2x keywords
    //

    KEYWORD_TOKEN_NODE_TYPE(CONCEPT_KEYWORD,        "concept");
    KEYWORD_TOKEN_NODE_TYPE(REQUIRES_KEYWORD,       "requires");

    // C++CLI keywords
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_GENERIC_KEYWORD,   "generic");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_WHERE_KEYWORD,     "where");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_REF_KEYWORD,       "ref");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_VALUE_KEYWORD,     "value");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_INTERFACE_KEYWORD, "interface");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_GCNEW_KEYWORD,     "gcnew");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_SAFE_CAST_KEYWORD, "safe_cast");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_INITONLY_KEYWORD,  "initonly");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_LITERAL_KEYWORD,   "literal");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_INTERNAL_KEYWORD,  "internal");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_PROPERTY_KEYWORD,  "property");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_EVENT_KEYWORD,     "event");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_DELEGATE_KEYWORD,  "delegate");
    KEYWORD_TOKEN_NODE_TYPE(CXXCLI_FINALLY_KEYWORD,   "finally");

    // MS Type Traits
    KEYWORD_TOKEN_NODE_TYPE(__HAS_ASSIGN,                   "__has_assign");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_COPY,                     "__has_copy");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_FINALIZER,                "__has_finalizer");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_NOTHROW_ASSIGN,           "__has_nothrow_assign");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_NOTHROW_CONSTRUCTOR,      "__has_nothrow_constructor");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_NOTHROW_COPY,             "__has_nothrow_copy");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_ASSIGN,           "__has_trivial_assign");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_CONSTRUCTOR,      "__has_trivial_constructor");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_COPY,             "__has_trivial_copy");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_DESTRUCTOR,       "__has_trivial_destructor");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_USER_DESTRUCTOR,          "__has_user_destructor");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_VIRTUAL_DESTRUCTOR,       "__has_virtual_destructor");
    KEYWORD_TOKEN_NODE_TYPE(__IS_ABSTRACT,                  "__is_abstract");
    KEYWORD_TOKEN_NODE_TYPE(__IS_AGGREGATE,                 "__is_aggregate");
    KEYWORD_TOKEN_NODE_TYPE(__IS_ASSIGNABLE,                "__is_assignable");
    KEYWORD_TOKEN_NODE_TYPE(__IS_BASE_OF,                   "__is_base_of");
    KEYWORD_TOKEN_NODE_TYPE(__IS_CLASS,                     "__is_class");
    KEYWORD_TOKEN_NODE_TYPE(__IS_CONVERTIBLE_TO,            "__is_convertible_to");
    KEYWORD_TOKEN_NODE_TYPE(__IS_DELEGATE,                  "__is_delegate");
    KEYWORD_TOKEN_NODE_TYPE(__IS_EMPTY,                     "__is_empty");
    KEYWORD_TOKEN_NODE_TYPE(__IS_ENUM,                      "__is_enum");
    KEYWORD_TOKEN_NODE_TYPE(__IS_FINAL,                     "__is_final");
    KEYWORD_TOKEN_NODE_TYPE(__IS_INTERFACE_CLASS,           "__is_interface_class");
    KEYWORD_TOKEN_NODE_TYPE(__IS_POD,                       "__is_pod");
    KEYWORD_TOKEN_NODE_TYPE(__IS_POLYMORPHIC,               "__is_polymorphic");
    KEYWORD_TOKEN_NODE_TYPE(__IS_REF_ARRAY,                 "__is_ref_array");
    KEYWORD_TOKEN_NODE_TYPE(__IS_REF_CLASS,                 "__is_ref_class");
    KEYWORD_TOKEN_NODE_TYPE(__IS_SEALED,                    "__is_sealed");
    KEYWORD_TOKEN_NODE_TYPE(__IS_SIMPLE_VALUE_CLASS,        "__is_simple_value_class");
    KEYWORD_TOKEN_NODE_TYPE(__IS_UNION,                     "__is_union");
    KEYWORD_TOKEN_NODE_TYPE(__IS_VALUE_CLASS,               "__is_value_class");
    KEYWORD_TOKEN_NODE_TYPE(__IS_STANDARD_LAYOUT,           "__is_standard_layout");
    KEYWORD_TOKEN_NODE_TYPE(__IS_LITERAL_TYPE,              "__is_literal_type");
    KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIAL,                   "__is_trivial");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_MOVE_CONSTRUCTOR, "__has_trivial_move_constructor");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_MOVE_ASSIGN,      "__has_trivial_move_assign");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_NOTHROW_MOVE_ASSIGN,      "__has_nothrow_move_assign");
    KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIALLY_COPYABLE,        "__is_trivially_copyable");
    KEYWORD_TOKEN_NODE_TYPE(__IS_CONSTRUCTIBLE,             "__is_constructible");
    KEYWORD_TOKEN_NODE_TYPE(__IS_DESTRUCTIBLE,              "__is_destructible");
    KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIALLY_CONSTRUCTIBLE,   "__is_trivially_constructible");
    KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIALLY_ASSIGNABLE,      "__is_trivially_assignable");
    KEYWORD_TOKEN_NODE_TYPE(__IS_NOTHROW_CONSTRUCTIBLE,     "__is_nothrow_constructible");
    KEYWORD_TOKEN_NODE_TYPE(__IS_NOTHROW_ASSIGNABLE,        "__is_nothrow_assignable");
    KEYWORD_TOKEN_NODE_TYPE(__IS_NOTHROW_DESTRUCTIBLE,      "__is_nothrow_destructible");
    KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIALLY_DESTRUCTIBLE,    "__is_trivially_destructible");
    KEYWORD_TOKEN_NODE_TYPE(__HAS_UNIQUE_OBJECT_REPRSENTATIONS, "__has_unique_object_representations");
    KEYWORD_TOKEN_NODE_TYPE(__IS_FUNCTION,                  "__is_function");

    // C++ coroutines
    KEYWORD_TOKEN_NODE_TYPE(CO_RETURN_KEYWORD,      "co_return");
    KEYWORD_TOKEN_NODE_TYPE(CO_AWAIT_KEYWORD,       "co_await");
    KEYWORD_TOKEN_NODE_TYPE(CO_YIELD_KEYWORD,       "co_yield");

    //
    // GNU and MS Type Traits
    //

    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_NO_THROW_ASSIGN_KEYWORD,        "__has_nothrow_assign");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_NO_THROW_COPY_KEYWORD,            "__has_nothrow_copy");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_NO_THROW_CONSTRUCTOR_KEYWORD,    "__has_nothrow_constructor");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_ASSIGN_KEYWORD,            "__has_trivial_assign");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_COPY_KEYWORD,            "__has_trivial_copy");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_CONSTRUCTOR_KEYWORD,    "__has_trivial_constructor");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_TRIVIAL_DESTRUCTOR_KEYWORD,        "__has_trivial_destructor");
    //   KEYWORD_TOKEN_NODE_TYPE(__HAS_VIRTUAL_DESTRUCTOR_KEYWORD,        "__has_virtual_destructor");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_ABSTRACT_KEYWORD,                "__is_abstract");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_BASE_OF_KEYWORD,                    "__is_base_of");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_CLASS_KEYWORD,                    "__is_class");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_CONVERTIBLE_TO_KEYWORD,            "__is_convertible_to");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_EMPTY_KEYWORD,                    "__is_empty");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_ENUM_KEYWORD,                    "__is_enum");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_FINAL_KEYWORD,                    "__is_final");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_LITERAL_KEYWORD,                    "__is_literal");

    //
    // Name for GCC 4.6 compatibility - people have already written libraries using this names unfortunately.
    //

    //   KEYWORD_TOKEN_NODE_TYPE(__IS_LITERAL_TYPE_KEYWORD,            "__is_literal_type");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_POD_KEYWORD,                        "__is_pod");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_POLYMORPHIC_KEYWORD,                "__is_polymorphic");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_TRIVIAL_KEYWORD,                    "__is_trivial");
    //   KEYWORD_TOKEN_NODE_TYPE(__IS_UNION_KEYWORD,                    "__is_union");


    //
    // Microsoft extensions
    //

    KEYWORD_TOKEN_NODE_TYPE(_DECL_SPEC_KEYWORD,         "_declspec");
    KEYWORD_TOKEN_NODE_TYPE(__DECL_SPEC_KEYWORD,        "__declspec");
    KEYWORD_TOKEN_NODE_TYPE(_CDECL_KEYWORD,             "_cdecl");
    KEYWORD_TOKEN_NODE_TYPE(__CDECL_KEYWORD,            "__cdecl");
    KEYWORD_TOKEN_NODE_TYPE(__CLRCALL_KEYWORD,          "__clrcall");
    KEYWORD_TOKEN_NODE_TYPE(_STDCALL_KEYWORD,           "_stdcall");
    KEYWORD_TOKEN_NODE_TYPE(__STDCALL_KEYWORD,          "__stdcall");
    KEYWORD_TOKEN_NODE_TYPE(_FASTCALL_KEYWORD,          "_fastcall");
    KEYWORD_TOKEN_NODE_TYPE(__FASTCALL_KEYWORD,         "__fastcall");
    KEYWORD_TOKEN_NODE_TYPE(_THISCALL_KEYWORD,          "_thiscall");
    KEYWORD_TOKEN_NODE_TYPE(__THISCALL_KEYWORD,         "__thiscall");
    KEYWORD_TOKEN_NODE_TYPE(_VECTORCALL_KEYWORD,        "_vectorcall");
    KEYWORD_TOKEN_NODE_TYPE(__VECTORCALL_KEYWORD,       "__vectorcall");
    KEYWORD_TOKEN_NODE_TYPE(_FORCEINLINE_KEYWORD,       "_forceinline");
    KEYWORD_TOKEN_NODE_TYPE(__FORCEINLINE_KEYWORD,      "__forceinline");
    KEYWORD_TOKEN_NODE_TYPE(_UNALIGNED_KEYWORD,         "_unaligned");
    KEYWORD_TOKEN_NODE_TYPE(__UNALIGNED_KEYWORD,        "__unaligned");
    KEYWORD_TOKEN_NODE_TYPE(__UNDERLYING_TYPE,          "__underlying_type");
    KEYWORD_TOKEN_NODE_TYPE(SEALED_KEYWORD,             "sealed");
    KEYWORD_TOKEN_NODE_TYPE(ABSTRACT_KEYWORD,           "abstract");
    KEYWORD_TOKEN_NODE_TYPE(TILE_STATIC_KEYWORD,        "tile_static");

    //
    // HLSL keywords
    //
    KEYWORD_TOKEN_NODE_TYPE(HALF_KEYWORD, "half");
    KEYWORD_TOKEN_NODE_TYPE(VECTOR_KEYWORD, "vector");
    KEYWORD_TOKEN_NODE_TYPE(MATRIX_KEYWORD, "matrix");
    KEYWORD_TOKEN_NODE_TYPE(STRING_KEYWORD, "string");
    KEYWORD_TOKEN_NODE_TYPE(SNORM_KEYWORD, "snorm");
    KEYWORD_TOKEN_NODE_TYPE(UNORM_KEYWORD, "unorm");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLER1D_KEYWORD, "sampler1D");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLER2D_KEYWORD, "sampler2D");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLER3D_KEYWORD, "sampler3D");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLERCUBE_KEYWORD, "samplerCUBE");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLERSTATE_KEYWORD, "SamplerState");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLER_COMPARISON_STATE_KEYWORD, "SamplerComparisonState");
    KEYWORD_TOKEN_NODE_TYPE(DISCARD_KEYWORD, "discard");
    KEYWORD_TOKEN_NODE_TYPE(PACKOFFSET_KEYWORD, "packoffset");

    // HLSL input modifiers
    KEYWORD_TOKEN_NODE_TYPE(IN_KEYWORD, "in");
    KEYWORD_TOKEN_NODE_TYPE(OUT_KEYWORD, "out");
    KEYWORD_TOKEN_NODE_TYPE(INOUT_KEYWORD, "inout");
    // HLSL storage class modifiers
    KEYWORD_TOKEN_NODE_TYPE(PRECISE_KEYWORD, "precise");
    KEYWORD_TOKEN_NODE_TYPE(SHARED_KEYWORD, "shared");
    KEYWORD_TOKEN_NODE_TYPE(GROUPSHARED_KEYWORD, "groupshared");
    KEYWORD_TOKEN_NODE_TYPE(UNIFORM_KEYWORD, "uniform");
    // HLSL type modifiers
    KEYWORD_TOKEN_NODE_TYPE(ROW_MAJOR_KEYWORD, "row_major");
    KEYWORD_TOKEN_NODE_TYPE(COLUMN_MAJOR_KEYWORD, "column_major");
    // HLSL interpolation modifiers
    KEYWORD_TOKEN_NODE_TYPE(LINEAR_KEYWORD, "linear");
    KEYWORD_TOKEN_NODE_TYPE(CENTROID_KEYWORD, "centroid");
    KEYWORD_TOKEN_NODE_TYPE(NOINTERPOLATION_KEYWORD, "nointerpolation");
    KEYWORD_TOKEN_NODE_TYPE(NOPERSPECTIVE_KEYWORD, "noperspective");
    KEYWORD_TOKEN_NODE_TYPE(SAMPLE_KEYWORD, "sample");
    // HLSL Geometry-Shader Object primitive types
    KEYWORD_TOKEN_NODE_TYPE(POINT_KEYWORD, "point");
    KEYWORD_TOKEN_NODE_TYPE(LINE_KEYWORD, "line");
    KEYWORD_TOKEN_NODE_TYPE(TRIANGLE_KEYWORD, "triangle");
    KEYWORD_TOKEN_NODE_TYPE(LINEADJ_KEYWORD, "lineadj");
    KEYWORD_TOKEN_NODE_TYPE(TRIANGLEADJ_KEYWORD, "triangleadj");

    KEYWORD_TOKEN_NODE_TYPE(CBUFFER_KEYWORD, "cbuffer");
    KEYWORD_TOKEN_NODE_TYPE(TBUFFER_KEYWORD, "tbuffer");

    // Microsoft extensions (which should be disabled in strict conformance mode)
                                                        
    KEYWORD_TOKEN_NODE_TYPE(__PRAGMA_KEYWORD,           "__pragma");
    KEYWORD_TOKEN_NODE_TYPE(__NULLPTR_KEYWORD,          "__nullptr");
    KEYWORD_TOKEN_NODE_TYPE(_PTR64_KEYWORD,             "_ptr64");
    KEYWORD_TOKEN_NODE_TYPE(__PTR64_KEYWORD,            "__ptr64");
    KEYWORD_TOKEN_NODE_TYPE(_PTR32_KEYWORD,             "_ptr32");
    KEYWORD_TOKEN_NODE_TYPE(__PTR32_KEYWORD,            "__ptr32");
    KEYWORD_TOKEN_NODE_TYPE(_SPTR_KEYWORD,             "_sptr");
    KEYWORD_TOKEN_NODE_TYPE(__SPTR_KEYWORD,            "__sptr");
    KEYWORD_TOKEN_NODE_TYPE(_UPTR_KEYWORD,             "_uptr");
    KEYWORD_TOKEN_NODE_TYPE(__UPTR_KEYWORD,            "__uptr");
    KEYWORD_TOKEN_NODE_TYPE(_W64_KEYWORD,               "_w64");
    KEYWORD_TOKEN_NODE_TYPE(__W64_KEYWORD,              "__w64");
    KEYWORD_TOKEN_NODE_TYPE(_UUIDOF_KEYWORD,            "_uuidof");
    KEYWORD_TOKEN_NODE_TYPE(__UUIDOF_KEYWORD,           "__uuidof");
    KEYWORD_TOKEN_NODE_TYPE(_ALIGNOF_KEYWORD,           "_alignof");
    KEYWORD_TOKEN_NODE_TYPE(__ALIGNOF_KEYWORD,          "__alignof");
    KEYWORD_TOKEN_NODE_TYPE(__BUILTIN_ALIGNOF_KEYWORD,  "__builtin_alignof");
    KEYWORD_TOKEN_NODE_TYPE(__BUILTIN_ADDRESSOF_KEYWORD, "__builtin_addressof");
    KEYWORD_TOKEN_NODE_TYPE(__BUILTIN_OFFSETOF_KEYWORD, "__builtin_offsetof");
    KEYWORD_TOKEN_NODE_TYPE(_TRY_KEYWORD,               "_try");
    KEYWORD_TOKEN_NODE_TYPE(__TRY_KEYWORD,              "__try");
    KEYWORD_TOKEN_NODE_TYPE(_EXCEPT_KEYWORD,            "_except");
    KEYWORD_TOKEN_NODE_TYPE(__EXCEPT_KEYWORD,           "__except");
    KEYWORD_TOKEN_NODE_TYPE(_FINALLY_KEYWORD,           "_finally");
    KEYWORD_TOKEN_NODE_TYPE(__FINALLY_KEYWORD,          "__finally");
    KEYWORD_TOKEN_NODE_TYPE(_LEAVE_KEYWORD,             "_leave");
    KEYWORD_TOKEN_NODE_TYPE(__LEAVE_KEYWORD,            "__leave");
    KEYWORD_TOKEN_NODE_TYPE(__IDENTIFIER_KEYWORD,       "__identifier");
    KEYWORD_TOKEN_NODE_TYPE(_ASM_KEYWORD,               "_asm");
    KEYWORD_TOKEN_NODE_TYPE(__ASM_KEYWORD,              "__asm");
    KEYWORD_TOKEN_NODE_TYPE(_INLINE_KEYWORD,            "_inline");
    KEYWORD_TOKEN_NODE_TYPE(__INLINE_KEYWORD,           "__inline");
    KEYWORD_TOKEN_NODE_TYPE(_RESTRICT_KEYWORD,          "_restrict");
    KEYWORD_TOKEN_NODE_TYPE(__RESTRICT_KEYWORD,         "__restrict");
    KEYWORD_TOKEN_NODE_TYPE(__INTERFACE_KEYWORD,        "__interface");
    KEYWORD_TOKEN_NODE_TYPE(__WCHAR_T_KEYWORD,          "__wchar_t");
    KEYWORD_TOKEN_NODE_TYPE(_INT8_KEYWORD,              "_int8");
    KEYWORD_TOKEN_NODE_TYPE(__INT8_KEYWORD,             "__int8");
    KEYWORD_TOKEN_NODE_TYPE(_INT16_KEYWORD,             "_int16");
    KEYWORD_TOKEN_NODE_TYPE(__INT16_KEYWORD,            "__int16");
    KEYWORD_TOKEN_NODE_TYPE(_INT32_KEYWORD,             "_int32");
    KEYWORD_TOKEN_NODE_TYPE(__INT32_KEYWORD,            "__int32");
    KEYWORD_TOKEN_NODE_TYPE(_INT64_KEYWORD,             "_int64");
    KEYWORD_TOKEN_NODE_TYPE(__INT64_KEYWORD,            "__int64");
    KEYWORD_TOKEN_NODE_TYPE(__INT128_KEYWORD,           "__int128");
    KEYWORD_TOKEN_NODE_TYPE(__IF_EXIST_KEYWORD,         "__if_exists");
    KEYWORD_TOKEN_NODE_TYPE(__IF_NOT_EXIST_KEYWORD,     "__if_not_exists");
    KEYWORD_TOKEN_NODE_TYPE(__NOOP_KEYWORD,             "__noop");
    KEYWORD_TOKEN_NODE_TYPE(_ASSUME_KEYWORD,            "_assume");
    KEYWORD_TOKEN_NODE_TYPE(__ASSUME_KEYWORD,           "__assume");
    KEYWORD_TOKEN_NODE_TYPE(__LPREFIX_KEYWORD,          "__LPREFIX");
    KEYWORD_TOKEN_NODE_TYPE(__SUPER_KEYWORD,            "__super");
    KEYWORD_TOKEN_NODE_TYPE(__EVENT_KEYWORD,            "__event");
    KEYWORD_TOKEN_NODE_TYPE(__RAISE_KEYWORD,            "__raise");
    KEYWORD_TOKEN_NODE_TYPE(__HOOK_KEYWORD,             "__hook");
    KEYWORD_TOKEN_NODE_TYPE(__UNHOOK_KEYWORD,           "__unhook");

    KEYWORD_TOKEN_NODE_TYPE(_SINGLE_INHERITANCE,        "_single_inheritance");
    KEYWORD_TOKEN_NODE_TYPE(__SINGLE_INHERITANCE,       "__single_inheritance");
    KEYWORD_TOKEN_NODE_TYPE(_MULTIPLE_INHERITANCE,      "_multiple_inheritance");
    KEYWORD_TOKEN_NODE_TYPE(__MULTIPLE_INHERITANCE,     "__multiple_inheritance");
    KEYWORD_TOKEN_NODE_TYPE(_VIRTUAL_INHERITANCE,       "_virtual_inheritance");
    KEYWORD_TOKEN_NODE_TYPE(__VIRTUAL_INHERITANCE,      "__virtual_inheritance");

    KEYWORD_TOKEN_NODE_TYPE(GNU_ATTRIBUTE_KEYWORD,      "__attribute__");

    //
    // ReSharper internal keywords
    //

    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UNKNOWN_TYPE,  "__resharper_unknown_type");

    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_DISABLE_SYNTAX_DETECTORS, "__resharper_disable_syntax_detectors");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_ENABLE_SYNTAX_DETECTORS,  "__resharper_enable_syntax_detectors");

    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_UCLASS, "__resharper_ue4_uclass");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_USTRUCT,"__resharper_ue4_ustruct");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_UENUM,  "__resharper_ue4_uenum");
	KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_UINTERFACE, "__resharper_ue4_uinterface");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_GENERATED_BODY, "__resharper_ue4_generated_body");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_GENERATED_BODY_LEGACY, "__resharper_ue4_generated_body_legacy");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_UFUNCTION, "__resharper_ue4_ufunction");
    KEYWORD_TOKEN_NODE_TYPE(__RESHARPER_UE4_UPROPERTY, "__resharper_ue4_uproperty");


    //
    // Punctuators
    //

    PUNCTUATOR_TOKEN_NODE_TYPE(LBRACKET,    "[");
    PUNCTUATOR_TOKEN_NODE_TYPE(RBRACKET,    "]");
    PUNCTUATOR_TOKEN_NODE_TYPE(LBRACE,      "{");
    PUNCTUATOR_TOKEN_NODE_TYPE(RBRACE,      "}");
    PUNCTUATOR_TOKEN_NODE_TYPE(LPAR,        "(");
    PUNCTUATOR_TOKEN_NODE_TYPE(RPAR,        ")");
    PUNCTUATOR_TOKEN_NODE_TYPE(DOT,         ".");
    PUNCTUATOR_TOKEN_NODE_TYPE(DEREF,       "->");
    PUNCTUATOR_TOKEN_NODE_TYPE(DOTMUL,      ".*");
    PUNCTUATOR_TOKEN_NODE_TYPE(DEREFMUL,    "->*");
    PUNCTUATOR_TOKEN_NODE_TYPE(PLUSPLUS,    "++");

    PUNCTUATOR_TOKEN_NODE_TYPE(MINUSMINUS,  "--");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(AND,     "&", "bitand");
    PUNCTUATOR_TOKEN_NODE_TYPE(MUL,         "*");
    PUNCTUATOR_TOKEN_NODE_TYPE(PLUS,        "+");
    PUNCTUATOR_TOKEN_NODE_TYPE(MINUS,       "-");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(TILDE,   "~", "compl");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(EXCL,    "!", "not");
    PUNCTUATOR_TOKEN_NODE_TYPE(DIV,         "/");
    PUNCTUATOR_TOKEN_NODE_TYPE(PERC,        "%");
    PUNCTUATOR_TOKEN_NODE_TYPE(LTLT,        "<<");
    PUNCTUATOR_TOKEN_NODE_TYPE(GTGT,        ">>");
    PUNCTUATOR_TOKEN_NODE_TYPE(LT,          "<");
    PUNCTUATOR_TOKEN_NODE_TYPE(GT,          ">");
    PUNCTUATOR_TOKEN_NODE_TYPE(LTEQ,        "<=");
    PUNCTUATOR_TOKEN_NODE_TYPE(GTEQ,        ">=");
    PUNCTUATOR_TOKEN_NODE_TYPE(EQEQ,        "==");
    PUNCTUATOR_TOKEN_NODE_TYPE(LTEQGT,      "<=>");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(EXCLEQ,  "!=", "not_eq");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(XOR,     "^", "xor");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(OR,      "|", "bitor");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(ANDAND,  "&&", "and");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(OROR,    "||", "or");
    PUNCTUATOR_TOKEN_NODE_TYPE(QUEST,       "?");
    PUNCTUATOR_TOKEN_NODE_TYPE(COLON,       ":");
    PUNCTUATOR_TOKEN_NODE_TYPE(COLON2X,     "::");
    PUNCTUATOR_TOKEN_NODE_TYPE(SEMICOLON,   ";");
    PUNCTUATOR_TOKEN_NODE_TYPE(ELLIPSIS,    "...");
    PUNCTUATOR_TOKEN_NODE_TYPE(EQ,          "=");
    PUNCTUATOR_TOKEN_NODE_TYPE(MULTEQ,      "*=");
    PUNCTUATOR_TOKEN_NODE_TYPE(DIVEQ,       "/=");
    PUNCTUATOR_TOKEN_NODE_TYPE(PERCEQ,      "%=");
    PUNCTUATOR_TOKEN_NODE_TYPE(PLUSEQ,      "+=");
    PUNCTUATOR_TOKEN_NODE_TYPE(MINUSEQ,     "-=");
    PUNCTUATOR_TOKEN_NODE_TYPE(LTLTEQ,      "<<=");
    PUNCTUATOR_TOKEN_NODE_TYPE(GTGTEQ,      ">>=");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(ANDEQ,   "&=", "and_eq");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(XOREQ,   "^=", "xor_eq");
    PUNCTUATOR_ALT_TOKEN_NODE_TYPE(OREQ,    "|=", "or_eq");
    PUNCTUATOR_TOKEN_NODE_TYPE(COMMA,       ",");
    PUNCTUATOR_TOKEN_NODE_TYPE(HASH,        "#");
    PUNCTUATOR_TOKEN_NODE_TYPE(HASHHASH,    "##");
    PUNCTUATOR_TOKEN_NODE_TYPE(HASHAT,      "#@");

    PUNCTUATOR_TOKEN_NODE_TYPE(BACKSLASH,   "\\");

    KEYWORD_TOKEN_NODE_TYPE(AND_KEYWORD,     "bitand");
    KEYWORD_TOKEN_NODE_TYPE(TILDE_KEYWORD,   "compl");
    KEYWORD_TOKEN_NODE_TYPE(EXCL_KEYWORD,    "not");
    KEYWORD_TOKEN_NODE_TYPE(EXCLEQ_KEYWORD,  "not_eq");
    KEYWORD_TOKEN_NODE_TYPE(XOR_KEYWORD,     "xor");
    KEYWORD_TOKEN_NODE_TYPE(OR_KEYWORD,      "bitor");
    KEYWORD_TOKEN_NODE_TYPE(ANDAND_KEYWORD,  "and");
    KEYWORD_TOKEN_NODE_TYPE(OROR_KEYWORD,    "or");
    KEYWORD_TOKEN_NODE_TYPE(ANDEQ_KEYWORD,   "and_eq");
    KEYWORD_TOKEN_NODE_TYPE(XOREQ_KEYWORD,   "xor_eq");
    KEYWORD_TOKEN_NODE_TYPE(OREQ_KEYWORD,    "or_eq");

#undef TOKEN_NODE_TYPE
#undef KEYWORD_TOKEN_NODE_TYPE
#undef PUNCTUATOR_TOKEN_NODE_TYPE
#undef PUNCTUATOR_ALT_TOKEN_NODE_TYPE
};
