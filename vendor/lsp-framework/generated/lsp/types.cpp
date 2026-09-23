/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#include "types.h"

namespace lsp{

void fromJson(json::Value&& json, OneOf<Command, CodeAction>& value)
{
	const auto* command = json.object().find("command");
	if(command && command->isString()) {
		value.emplace<Command>();
		fromJson(std::move(json), std::get<Command>(value));
	} else {
		value.emplace<CodeAction>();
		fromJson(std::move(json), std::get<CodeAction>(value));
	}
}

#if defined(__clang__) || defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter
#endif

template<>
const SemanticTokenTypesEnum::ConstInitType SemanticTokenTypesEnum::s_values[] = {
	"namespace",
	"type",
	"class",
	"enum",
	"interface",
	"struct",
	"typeParameter",
	"parameter",
	"variable",
	"property",
	"enumMember",
	"event",
	"function",
	"method",
	"macro",
	"keyword",
	"modifier",
	"comment",
	"string",
	"number",
	"regexp",
	"operator",
	"decorator",
	"label",
};

template<>
const SemanticTokenModifiersEnum::ConstInitType SemanticTokenModifiersEnum::s_values[] = {
	"declaration",
	"definition",
	"readonly",
	"static",
	"deprecated",
	"abstract",
	"async",
	"modification",
	"documentation",
	"defaultLibrary",
};

template<>
const DocumentDiagnosticReportKindEnum::ConstInitType DocumentDiagnosticReportKindEnum::s_values[] = {
	"full",
	"unchanged",
};

template<>
const ErrorCodesEnum::ConstInitType ErrorCodesEnum::s_values[] = {
	-32700,
	-32600,
	-32601,
	-32602,
	-32603,
	-32002,
	-32001,
};

template<>
const LSPErrorCodesEnum::ConstInitType LSPErrorCodesEnum::s_values[] = {
	-32803,
	-32802,
	-32801,
	-32800,
};

template<>
const FoldingRangeKindEnum::ConstInitType FoldingRangeKindEnum::s_values[] = {
	"comment",
	"imports",
	"region",
};

template<>
const SymbolKindEnum::ConstInitType SymbolKindEnum::s_values[] = {
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
};

template<>
const SymbolTagEnum::ConstInitType SymbolTagEnum::s_values[] = {
	1,
};

template<>
const UniquenessLevelEnum::ConstInitType UniquenessLevelEnum::s_values[] = {
	"document",
	"project",
	"group",
	"scheme",
	"global",
};

template<>
const MonikerKindEnum::ConstInitType MonikerKindEnum::s_values[] = {
	"import",
	"export",
	"local",
};

template<>
const InlayHintKindEnum::ConstInitType InlayHintKindEnum::s_values[] = {
	1,
	2,
};

template<>
const MessageTypeEnum::ConstInitType MessageTypeEnum::s_values[] = {
	1,
	2,
	3,
	4,
	5,
};

template<>
const TextDocumentSyncKindEnum::ConstInitType TextDocumentSyncKindEnum::s_values[] = {
	0,
	1,
	2,
};

template<>
const TextDocumentSaveReasonEnum::ConstInitType TextDocumentSaveReasonEnum::s_values[] = {
	1,
	2,
	3,
};

template<>
const CompletionItemKindEnum::ConstInitType CompletionItemKindEnum::s_values[] = {
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
};

template<>
const CompletionItemTagEnum::ConstInitType CompletionItemTagEnum::s_values[] = {
	1,
};

template<>
const InsertTextFormatEnum::ConstInitType InsertTextFormatEnum::s_values[] = {
	1,
	2,
};

template<>
const InsertTextModeEnum::ConstInitType InsertTextModeEnum::s_values[] = {
	1,
	2,
};

template<>
const DocumentHighlightKindEnum::ConstInitType DocumentHighlightKindEnum::s_values[] = {
	1,
	2,
	3,
};

template<>
const CodeActionKindEnum::ConstInitType CodeActionKindEnum::s_values[] = {
	"",
	"quickfix",
	"refactor",
	"refactor.extract",
	"refactor.inline",
	"refactor.move",
	"refactor.rewrite",
	"source",
	"source.organizeImports",
	"source.fixAll",
	"notebook",
};

template<>
const CodeActionTagEnum::ConstInitType CodeActionTagEnum::s_values[] = {
	1,
};

template<>
const TraceValueEnum::ConstInitType TraceValueEnum::s_values[] = {
	"off",
	"messages",
	"verbose",
};

template<>
const MarkupKindEnum::ConstInitType MarkupKindEnum::s_values[] = {
	"plaintext",
	"markdown",
};

template<>
const LanguageKindEnum::ConstInitType LanguageKindEnum::s_values[] = {
	"abap",
	"bat",
	"bibtex",
	"clojure",
	"coffeescript",
	"c",
	"cpp",
	"csharp",
	"css",
	"d",
	"pascal",
	"diff",
	"dart",
	"dockerfile",
	"elixir",
	"erlang",
	"fsharp",
	"git-commit",
	"git-rebase",
	"go",
	"groovy",
	"handlebars",
	"haskell",
	"html",
	"ini",
	"java",
	"javascript",
	"javascriptreact",
	"json",
	"latex",
	"less",
	"lua",
	"makefile",
	"markdown",
	"objective-c",
	"objective-cpp",
	"pascal",
	"perl",
	"perl6",
	"php",
	"plaintext",
	"powershell",
	"jade",
	"python",
	"r",
	"razor",
	"ruby",
	"rust",
	"scss",
	"sass",
	"scala",
	"shaderlab",
	"shellscript",
	"sql",
	"swift",
	"typescript",
	"typescriptreact",
	"tex",
	"vb",
	"xml",
	"xsl",
	"yaml",
};

template<>
const InlineCompletionTriggerKindEnum::ConstInitType InlineCompletionTriggerKindEnum::s_values[] = {
	1,
	2,
};

template<>
const PositionEncodingKindEnum::ConstInitType PositionEncodingKindEnum::s_values[] = {
	"utf-8",
	"utf-16",
	"utf-32",
};

template<>
const FileChangeTypeEnum::ConstInitType FileChangeTypeEnum::s_values[] = {
	1,
	2,
	3,
};

template<>
const WatchKindEnum::ConstInitType WatchKindEnum::s_values[] = {
	1,
	2,
	4,
};

template<>
const DiagnosticSeverityEnum::ConstInitType DiagnosticSeverityEnum::s_values[] = {
	1,
	2,
	3,
	4,
};

template<>
const DiagnosticTagEnum::ConstInitType DiagnosticTagEnum::s_values[] = {
	1,
	2,
};

template<>
const CompletionTriggerKindEnum::ConstInitType CompletionTriggerKindEnum::s_values[] = {
	1,
	2,
	3,
};

template<>
const ApplyKindEnum::ConstInitType ApplyKindEnum::s_values[] = {
	1,
	2,
};

template<>
const SignatureHelpTriggerKindEnum::ConstInitType SignatureHelpTriggerKindEnum::s_values[] = {
	1,
	2,
	3,
};

template<>
const CodeActionTriggerKindEnum::ConstInitType CodeActionTriggerKindEnum::s_values[] = {
	1,
	2,
};

template<>
const FileOperationPatternKindEnum::ConstInitType FileOperationPatternKindEnum::s_values[] = {
	"file",
	"folder",
};

template<>
const NotebookCellKindEnum::ConstInitType NotebookCellKindEnum::s_values[] = {
	1,
	2,
};

template<>
const ResourceOperationKindEnum::ConstInitType ResourceOperationKindEnum::s_values[] = {
	"create",
	"rename",
	"delete",
};

template<>
const FailureHandlingKindEnum::ConstInitType FailureHandlingKindEnum::s_values[] = {
	"abort",
	"transactional",
	"textOnlyTransactional",
	"undo",
};

template<>
const PrepareSupportDefaultBehaviorEnum::ConstInitType PrepareSupportDefaultBehaviorEnum::s_values[] = {
	1,
};

template<>
const TokenFormatEnum::ConstInitType TokenFormatEnum::s_values[] = {
	"relative",
};

static void textDocumentIdentifierFromJson(json::Object& json, TextDocumentIdentifier& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, TextDocumentIdentifier& value)
{
	auto& obj = json.object();
	textDocumentIdentifierFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentIdentifier>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void positionFromJson(json::Object& json, Position& value)
{
	fromJson(std::move(json.get("line")), value.line);
	fromJson(std::move(json.get("character")), value.character);
}

void fromJson(json::Value&& json, Position& value)
{
	auto& obj = json.object();
	positionFromJson(obj, value);
}

template<>
auto requiredProperties<Position>() -> const char**
{
	static const char* properties[] = {
		"line",
		"character",
		nullptr
	};
	return properties;
}

static void textDocumentPositionParamsFromJson(json::Object& json, TextDocumentPositionParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("position")), value.position);
}

void fromJson(json::Value&& json, TextDocumentPositionParams& value)
{
	auto& obj = json.object();
	textDocumentPositionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentPositionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void workDoneProgressParamsFromJson(json::Object& json, WorkDoneProgressParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, WorkDoneProgressParams& value)
{
	auto& obj = json.object();
	workDoneProgressParamsFromJson(obj, value);
}

static void partialResultParamsFromJson(json::Object& json, PartialResultParams& value)
{
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, PartialResultParams& value)
{
	auto& obj = json.object();
	partialResultParamsFromJson(obj, value);
}

static void implementationParamsFromJson(json::Object& json, ImplementationParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, ImplementationParams& value)
{
	auto& obj = json.object();
	implementationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ImplementationParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void rangeFromJson(json::Object& json, Range& value)
{
	fromJson(std::move(json.get("start")), value.start);
	fromJson(std::move(json.get("end")), value.end);
}

void fromJson(json::Value&& json, Range& value)
{
	auto& obj = json.object();
	rangeFromJson(obj, value);
}

template<>
auto requiredProperties<Range>() -> const char**
{
	static const char* properties[] = {
		"start",
		"end",
		nullptr
	};
	return properties;
}

static void locationFromJson(json::Object& json, Location& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("range")), value.range);
}

void fromJson(json::Value&& json, Location& value)
{
	auto& obj = json.object();
	locationFromJson(obj, value);
}

template<>
auto requiredProperties<Location>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"range",
		nullptr
	};
	return properties;
}

static void workspaceFolderFromJson(json::Object& json, WorkspaceFolder& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("name")), value.name);
}

void fromJson(json::Value&& json, WorkspaceFolder& value)
{
	auto& obj = json.object();
	workspaceFolderFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceFolder>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"name",
		nullptr
	};
	return properties;
}

static void relativePatternFromJson(json::Object& json, RelativePattern& value)
{
	fromJson(std::move(json.get("baseUri")), value.baseUri);
	fromJson(std::move(json.get("pattern")), value.pattern);
}

void fromJson(json::Value&& json, RelativePattern& value)
{
	auto& obj = json.object();
	relativePatternFromJson(obj, value);
}

template<>
auto requiredProperties<RelativePattern>() -> const char**
{
	static const char* properties[] = {
		"baseUri",
		"pattern",
		nullptr
	};
	return properties;
}

static void textDocumentFilterLanguageFromJson(json::Object& json, TextDocumentFilterLanguage& value)
{
	fromJson(std::move(json.get("language")), value.language);
	if(auto* const v = json.find("scheme"))
		fromJson(std::move(*v), value.scheme);
	if(auto* const v = json.find("pattern"))
		fromJson(std::move(*v), value.pattern);
}

void fromJson(json::Value&& json, TextDocumentFilterLanguage& value)
{
	auto& obj = json.object();
	textDocumentFilterLanguageFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentFilterLanguage>() -> const char**
{
	static const char* properties[] = {
		"language",
		nullptr
	};
	return properties;
}

static void textDocumentFilterSchemeFromJson(json::Object& json, TextDocumentFilterScheme& value)
{
	fromJson(std::move(json.get("scheme")), value.scheme);
	if(auto* const v = json.find("language"))
		fromJson(std::move(*v), value.language);
	if(auto* const v = json.find("pattern"))
		fromJson(std::move(*v), value.pattern);
}

void fromJson(json::Value&& json, TextDocumentFilterScheme& value)
{
	auto& obj = json.object();
	textDocumentFilterSchemeFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentFilterScheme>() -> const char**
{
	static const char* properties[] = {
		"scheme",
		nullptr
	};
	return properties;
}

static void textDocumentFilterPatternFromJson(json::Object& json, TextDocumentFilterPattern& value)
{
	fromJson(std::move(json.get("pattern")), value.pattern);
	if(auto* const v = json.find("language"))
		fromJson(std::move(*v), value.language);
	if(auto* const v = json.find("scheme"))
		fromJson(std::move(*v), value.scheme);
}

void fromJson(json::Value&& json, TextDocumentFilterPattern& value)
{
	auto& obj = json.object();
	textDocumentFilterPatternFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentFilterPattern>() -> const char**
{
	static const char* properties[] = {
		"pattern",
		nullptr
	};
	return properties;
}

static void notebookDocumentFilterNotebookTypeFromJson(json::Object& json, NotebookDocumentFilterNotebookType& value)
{
	fromJson(std::move(json.get("notebookType")), value.notebookType);
	if(auto* const v = json.find("scheme"))
		fromJson(std::move(*v), value.scheme);
	if(auto* const v = json.find("pattern"))
		fromJson(std::move(*v), value.pattern);
}

void fromJson(json::Value&& json, NotebookDocumentFilterNotebookType& value)
{
	auto& obj = json.object();
	notebookDocumentFilterNotebookTypeFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentFilterNotebookType>() -> const char**
{
	static const char* properties[] = {
		"notebookType",
		nullptr
	};
	return properties;
}

static void notebookDocumentFilterSchemeFromJson(json::Object& json, NotebookDocumentFilterScheme& value)
{
	fromJson(std::move(json.get("scheme")), value.scheme);
	if(auto* const v = json.find("notebookType"))
		fromJson(std::move(*v), value.notebookType);
	if(auto* const v = json.find("pattern"))
		fromJson(std::move(*v), value.pattern);
}

void fromJson(json::Value&& json, NotebookDocumentFilterScheme& value)
{
	auto& obj = json.object();
	notebookDocumentFilterSchemeFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentFilterScheme>() -> const char**
{
	static const char* properties[] = {
		"scheme",
		nullptr
	};
	return properties;
}

static void notebookDocumentFilterPatternFromJson(json::Object& json, NotebookDocumentFilterPattern& value)
{
	fromJson(std::move(json.get("pattern")), value.pattern);
	if(auto* const v = json.find("notebookType"))
		fromJson(std::move(*v), value.notebookType);
	if(auto* const v = json.find("scheme"))
		fromJson(std::move(*v), value.scheme);
}

void fromJson(json::Value&& json, NotebookDocumentFilterPattern& value)
{
	auto& obj = json.object();
	notebookDocumentFilterPatternFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentFilterPattern>() -> const char**
{
	static const char* properties[] = {
		"pattern",
		nullptr
	};
	return properties;
}

static void notebookCellTextDocumentFilterFromJson(json::Object& json, NotebookCellTextDocumentFilter& value)
{
	fromJson(std::move(json.get("notebook")), value.notebook);
	if(auto* const v = json.find("language"))
		fromJson(std::move(*v), value.language);
}

void fromJson(json::Value&& json, NotebookCellTextDocumentFilter& value)
{
	auto& obj = json.object();
	notebookCellTextDocumentFilterFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookCellTextDocumentFilter>() -> const char**
{
	static const char* properties[] = {
		"notebook",
		nullptr
	};
	return properties;
}

static void textDocumentRegistrationOptionsFromJson(json::Object& json, TextDocumentRegistrationOptions& value)
{
	fromJson(std::move(json.get("documentSelector")), value.documentSelector);
}

void fromJson(json::Value&& json, TextDocumentRegistrationOptions& value)
{
	auto& obj = json.object();
	textDocumentRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void workDoneProgressOptionsFromJson(json::Object& json, WorkDoneProgressOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, WorkDoneProgressOptions& value)
{
	auto& obj = json.object();
	workDoneProgressOptionsFromJson(obj, value);
}

static void implementationOptionsFromJson(json::Object& json, ImplementationOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, ImplementationOptions& value)
{
	auto& obj = json.object();
	implementationOptionsFromJson(obj, value);
}

static void staticRegistrationOptionsFromJson(json::Object& json, StaticRegistrationOptions& value)
{
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, StaticRegistrationOptions& value)
{
	auto& obj = json.object();
	staticRegistrationOptionsFromJson(obj, value);
}

static void implementationRegistrationOptionsFromJson(json::Object& json, ImplementationRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	implementationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, ImplementationRegistrationOptions& value)
{
	auto& obj = json.object();
	implementationRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ImplementationRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void typeDefinitionParamsFromJson(json::Object& json, TypeDefinitionParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, TypeDefinitionParams& value)
{
	auto& obj = json.object();
	typeDefinitionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeDefinitionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void typeDefinitionOptionsFromJson(json::Object& json, TypeDefinitionOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, TypeDefinitionOptions& value)
{
	auto& obj = json.object();
	typeDefinitionOptionsFromJson(obj, value);
}

static void typeDefinitionRegistrationOptionsFromJson(json::Object& json, TypeDefinitionRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	typeDefinitionOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, TypeDefinitionRegistrationOptions& value)
{
	auto& obj = json.object();
	typeDefinitionRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeDefinitionRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void workspaceFoldersChangeEventFromJson(json::Object& json, WorkspaceFoldersChangeEvent& value)
{
	fromJson(std::move(json.get("added")), value.added);
	fromJson(std::move(json.get("removed")), value.removed);
}

void fromJson(json::Value&& json, WorkspaceFoldersChangeEvent& value)
{
	auto& obj = json.object();
	workspaceFoldersChangeEventFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceFoldersChangeEvent>() -> const char**
{
	static const char* properties[] = {
		"added",
		"removed",
		nullptr
	};
	return properties;
}

static void didChangeWorkspaceFoldersParamsFromJson(json::Object& json, DidChangeWorkspaceFoldersParams& value)
{
	fromJson(std::move(json.get("event")), value.event);
}

void fromJson(json::Value&& json, DidChangeWorkspaceFoldersParams& value)
{
	auto& obj = json.object();
	didChangeWorkspaceFoldersParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeWorkspaceFoldersParams>() -> const char**
{
	static const char* properties[] = {
		"event",
		nullptr
	};
	return properties;
}

static void configurationItemFromJson(json::Object& json, ConfigurationItem& value)
{
	if(auto* const v = json.find("scopeUri"))
		fromJson(std::move(*v), value.scopeUri);
	if(auto* const v = json.find("section"))
		fromJson(std::move(*v), value.section);
}

void fromJson(json::Value&& json, ConfigurationItem& value)
{
	auto& obj = json.object();
	configurationItemFromJson(obj, value);
}

static void configurationParamsFromJson(json::Object& json, ConfigurationParams& value)
{
	fromJson(std::move(json.get("items")), value.items);
}

void fromJson(json::Value&& json, ConfigurationParams& value)
{
	auto& obj = json.object();
	configurationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ConfigurationParams>() -> const char**
{
	static const char* properties[] = {
		"items",
		nullptr
	};
	return properties;
}

static void documentColorParamsFromJson(json::Object& json, DocumentColorParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, DocumentColorParams& value)
{
	auto& obj = json.object();
	documentColorParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentColorParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void colorFromJson(json::Object& json, Color& value)
{
	fromJson(std::move(json.get("red")), value.red);
	fromJson(std::move(json.get("green")), value.green);
	fromJson(std::move(json.get("blue")), value.blue);
	fromJson(std::move(json.get("alpha")), value.alpha);
}

void fromJson(json::Value&& json, Color& value)
{
	auto& obj = json.object();
	colorFromJson(obj, value);
}

template<>
auto requiredProperties<Color>() -> const char**
{
	static const char* properties[] = {
		"red",
		"green",
		"blue",
		"alpha",
		nullptr
	};
	return properties;
}

static void colorInformationFromJson(json::Object& json, ColorInformation& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("color")), value.color);
}

void fromJson(json::Value&& json, ColorInformation& value)
{
	auto& obj = json.object();
	colorInformationFromJson(obj, value);
}

template<>
auto requiredProperties<ColorInformation>() -> const char**
{
	static const char* properties[] = {
		"range",
		"color",
		nullptr
	};
	return properties;
}

static void documentColorOptionsFromJson(json::Object& json, DocumentColorOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, DocumentColorOptions& value)
{
	auto& obj = json.object();
	documentColorOptionsFromJson(obj, value);
}

static void documentColorRegistrationOptionsFromJson(json::Object& json, DocumentColorRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentColorOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, DocumentColorRegistrationOptions& value)
{
	auto& obj = json.object();
	documentColorRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentColorRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void colorPresentationParamsFromJson(json::Object& json, ColorPresentationParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("color")), value.color);
	fromJson(std::move(json.get("range")), value.range);
}

void fromJson(json::Value&& json, ColorPresentationParams& value)
{
	auto& obj = json.object();
	colorPresentationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ColorPresentationParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"color",
		"range",
		nullptr
	};
	return properties;
}

static void textEditFromJson(json::Object& json, TextEdit& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("newText")), value.newText);
}

void fromJson(json::Value&& json, TextEdit& value)
{
	auto& obj = json.object();
	textEditFromJson(obj, value);
}

template<>
auto requiredProperties<TextEdit>() -> const char**
{
	static const char* properties[] = {
		"range",
		"newText",
		nullptr
	};
	return properties;
}

static void colorPresentationFromJson(json::Object& json, ColorPresentation& value)
{
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("textEdit"))
		fromJson(std::move(*v), value.textEdit);
	if(auto* const v = json.find("additionalTextEdits"))
		fromJson(std::move(*v), value.additionalTextEdits);
}

void fromJson(json::Value&& json, ColorPresentation& value)
{
	auto& obj = json.object();
	colorPresentationFromJson(obj, value);
}

template<>
auto requiredProperties<ColorPresentation>() -> const char**
{
	static const char* properties[] = {
		"label",
		nullptr
	};
	return properties;
}

static void foldingRangeParamsFromJson(json::Object& json, FoldingRangeParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, FoldingRangeParams& value)
{
	auto& obj = json.object();
	foldingRangeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<FoldingRangeParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void foldingRangeFromJson(json::Object& json, FoldingRange& value)
{
	fromJson(std::move(json.get("startLine")), value.startLine);
	fromJson(std::move(json.get("endLine")), value.endLine);
	if(auto* const v = json.find("startCharacter"))
		fromJson(std::move(*v), value.startCharacter);
	if(auto* const v = json.find("endCharacter"))
		fromJson(std::move(*v), value.endCharacter);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
	if(auto* const v = json.find("collapsedText"))
		fromJson(std::move(*v), value.collapsedText);
}

void fromJson(json::Value&& json, FoldingRange& value)
{
	auto& obj = json.object();
	foldingRangeFromJson(obj, value);
}

template<>
auto requiredProperties<FoldingRange>() -> const char**
{
	static const char* properties[] = {
		"startLine",
		"endLine",
		nullptr
	};
	return properties;
}

static void foldingRangeOptionsFromJson(json::Object& json, FoldingRangeOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, FoldingRangeOptions& value)
{
	auto& obj = json.object();
	foldingRangeOptionsFromJson(obj, value);
}

static void foldingRangeRegistrationOptionsFromJson(json::Object& json, FoldingRangeRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	foldingRangeOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, FoldingRangeRegistrationOptions& value)
{
	auto& obj = json.object();
	foldingRangeRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<FoldingRangeRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void declarationParamsFromJson(json::Object& json, DeclarationParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, DeclarationParams& value)
{
	auto& obj = json.object();
	declarationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DeclarationParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void declarationOptionsFromJson(json::Object& json, DeclarationOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, DeclarationOptions& value)
{
	auto& obj = json.object();
	declarationOptionsFromJson(obj, value);
}

static void declarationRegistrationOptionsFromJson(json::Object& json, DeclarationRegistrationOptions& value)
{
	declarationOptionsFromJson(json, value);
	textDocumentRegistrationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, DeclarationRegistrationOptions& value)
{
	auto& obj = json.object();
	declarationRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DeclarationRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void selectionRangeParamsFromJson(json::Object& json, SelectionRangeParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("positions")), value.positions);
}

void fromJson(json::Value&& json, SelectionRangeParams& value)
{
	auto& obj = json.object();
	selectionRangeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SelectionRangeParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"positions",
		nullptr
	};
	return properties;
}

static void selectionRangeFromJson(json::Object& json, SelectionRange& value)
{
	fromJson(std::move(json.get("range")), value.range);
	if(auto* const v = json.find("parent"))
		fromJson(std::move(*v), value.parent);
}

void fromJson(json::Value&& json, SelectionRange& value)
{
	auto& obj = json.object();
	selectionRangeFromJson(obj, value);
}

template<>
auto requiredProperties<SelectionRange>() -> const char**
{
	static const char* properties[] = {
		"range",
		nullptr
	};
	return properties;
}

static void selectionRangeOptionsFromJson(json::Object& json, SelectionRangeOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, SelectionRangeOptions& value)
{
	auto& obj = json.object();
	selectionRangeOptionsFromJson(obj, value);
}

static void selectionRangeRegistrationOptionsFromJson(json::Object& json, SelectionRangeRegistrationOptions& value)
{
	selectionRangeOptionsFromJson(json, value);
	textDocumentRegistrationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, SelectionRangeRegistrationOptions& value)
{
	auto& obj = json.object();
	selectionRangeRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<SelectionRangeRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void workDoneProgressCreateParamsFromJson(json::Object& json, WorkDoneProgressCreateParams& value)
{
	fromJson(std::move(json.get("token")), value.token);
}

void fromJson(json::Value&& json, WorkDoneProgressCreateParams& value)
{
	auto& obj = json.object();
	workDoneProgressCreateParamsFromJson(obj, value);
}

template<>
auto requiredProperties<WorkDoneProgressCreateParams>() -> const char**
{
	static const char* properties[] = {
		"token",
		nullptr
	};
	return properties;
}

static void workDoneProgressCancelParamsFromJson(json::Object& json, WorkDoneProgressCancelParams& value)
{
	fromJson(std::move(json.get("token")), value.token);
}

void fromJson(json::Value&& json, WorkDoneProgressCancelParams& value)
{
	auto& obj = json.object();
	workDoneProgressCancelParamsFromJson(obj, value);
}

template<>
auto requiredProperties<WorkDoneProgressCancelParams>() -> const char**
{
	static const char* properties[] = {
		"token",
		nullptr
	};
	return properties;
}

static void callHierarchyPrepareParamsFromJson(json::Object& json, CallHierarchyPrepareParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, CallHierarchyPrepareParams& value)
{
	auto& obj = json.object();
	callHierarchyPrepareParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyPrepareParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void callHierarchyItemFromJson(json::Object& json, CallHierarchyItem& value)
{
	fromJson(std::move(json.get("name")), value.name);
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("selectionRange")), value.selectionRange);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("detail"))
		fromJson(std::move(*v), value.detail);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, CallHierarchyItem& value)
{
	auto& obj = json.object();
	callHierarchyItemFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyItem>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		"uri",
		"range",
		"selectionRange",
		nullptr
	};
	return properties;
}

static void callHierarchyOptionsFromJson(json::Object& json, CallHierarchyOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, CallHierarchyOptions& value)
{
	auto& obj = json.object();
	callHierarchyOptionsFromJson(obj, value);
}

static void callHierarchyRegistrationOptionsFromJson(json::Object& json, CallHierarchyRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	callHierarchyOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, CallHierarchyRegistrationOptions& value)
{
	auto& obj = json.object();
	callHierarchyRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void callHierarchyIncomingCallsParamsFromJson(json::Object& json, CallHierarchyIncomingCallsParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("item")), value.item);
}

void fromJson(json::Value&& json, CallHierarchyIncomingCallsParams& value)
{
	auto& obj = json.object();
	callHierarchyIncomingCallsParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyIncomingCallsParams>() -> const char**
{
	static const char* properties[] = {
		"item",
		nullptr
	};
	return properties;
}

static void callHierarchyIncomingCallFromJson(json::Object& json, CallHierarchyIncomingCall& value)
{
	fromJson(std::move(json.get("from")), value.from);
	fromJson(std::move(json.get("fromRanges")), value.fromRanges);
}

void fromJson(json::Value&& json, CallHierarchyIncomingCall& value)
{
	auto& obj = json.object();
	callHierarchyIncomingCallFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyIncomingCall>() -> const char**
{
	static const char* properties[] = {
		"from",
		"fromRanges",
		nullptr
	};
	return properties;
}

static void callHierarchyOutgoingCallsParamsFromJson(json::Object& json, CallHierarchyOutgoingCallsParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("item")), value.item);
}

void fromJson(json::Value&& json, CallHierarchyOutgoingCallsParams& value)
{
	auto& obj = json.object();
	callHierarchyOutgoingCallsParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyOutgoingCallsParams>() -> const char**
{
	static const char* properties[] = {
		"item",
		nullptr
	};
	return properties;
}

static void callHierarchyOutgoingCallFromJson(json::Object& json, CallHierarchyOutgoingCall& value)
{
	fromJson(std::move(json.get("to")), value.to);
	fromJson(std::move(json.get("fromRanges")), value.fromRanges);
}

void fromJson(json::Value&& json, CallHierarchyOutgoingCall& value)
{
	auto& obj = json.object();
	callHierarchyOutgoingCallFromJson(obj, value);
}

template<>
auto requiredProperties<CallHierarchyOutgoingCall>() -> const char**
{
	static const char* properties[] = {
		"to",
		"fromRanges",
		nullptr
	};
	return properties;
}

static void semanticTokensParamsFromJson(json::Object& json, SemanticTokensParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, SemanticTokensParams& value)
{
	auto& obj = json.object();
	semanticTokensParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void semanticTokensFromJson(json::Object& json, SemanticTokens& value)
{
	fromJson(std::move(json.get("data")), value.data);
	if(auto* const v = json.find("resultId"))
		fromJson(std::move(*v), value.resultId);
}

void fromJson(json::Value&& json, SemanticTokens& value)
{
	auto& obj = json.object();
	semanticTokensFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokens>() -> const char**
{
	static const char* properties[] = {
		"data",
		nullptr
	};
	return properties;
}

static void semanticTokensPartialResultFromJson(json::Object& json, SemanticTokensPartialResult& value)
{
	fromJson(std::move(json.get("data")), value.data);
}

void fromJson(json::Value&& json, SemanticTokensPartialResult& value)
{
	auto& obj = json.object();
	semanticTokensPartialResultFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensPartialResult>() -> const char**
{
	static const char* properties[] = {
		"data",
		nullptr
	};
	return properties;
}

static void semanticTokensLegendFromJson(json::Object& json, SemanticTokensLegend& value)
{
	fromJson(std::move(json.get("tokenTypes")), value.tokenTypes);
	fromJson(std::move(json.get("tokenModifiers")), value.tokenModifiers);
}

void fromJson(json::Value&& json, SemanticTokensLegend& value)
{
	auto& obj = json.object();
	semanticTokensLegendFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensLegend>() -> const char**
{
	static const char* properties[] = {
		"tokenTypes",
		"tokenModifiers",
		nullptr
	};
	return properties;
}

static void semanticTokensOptionsRangeFromJson(json::Object& json, SemanticTokensOptionsRange& value)
{
}

void fromJson(json::Value&& json, SemanticTokensOptionsRange& value)
{
	auto& obj = json.object();
	semanticTokensOptionsRangeFromJson(obj, value);
}

static void semanticTokensFullDeltaFromJson(json::Object& json, SemanticTokensFullDelta& value)
{
	if(auto* const v = json.find("delta"))
		fromJson(std::move(*v), value.delta);
}

void fromJson(json::Value&& json, SemanticTokensFullDelta& value)
{
	auto& obj = json.object();
	semanticTokensFullDeltaFromJson(obj, value);
}

static void semanticTokensOptionsFromJson(json::Object& json, SemanticTokensOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	fromJson(std::move(json.get("legend")), value.legend);
	if(auto* const v = json.find("range"))
		fromJson(std::move(*v), value.range);
	if(auto* const v = json.find("full"))
		fromJson(std::move(*v), value.full);
}

void fromJson(json::Value&& json, SemanticTokensOptions& value)
{
	auto& obj = json.object();
	semanticTokensOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensOptions>() -> const char**
{
	static const char* properties[] = {
		"legend",
		nullptr
	};
	return properties;
}

static void semanticTokensRegistrationOptionsFromJson(json::Object& json, SemanticTokensRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	semanticTokensOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, SemanticTokensRegistrationOptions& value)
{
	auto& obj = json.object();
	semanticTokensRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		"legend",
		nullptr
	};
	return properties;
}

static void semanticTokensDeltaParamsFromJson(json::Object& json, SemanticTokensDeltaParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("previousResultId")), value.previousResultId);
}

void fromJson(json::Value&& json, SemanticTokensDeltaParams& value)
{
	auto& obj = json.object();
	semanticTokensDeltaParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensDeltaParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"previousResultId",
		nullptr
	};
	return properties;
}

static void semanticTokensEditFromJson(json::Object& json, SemanticTokensEdit& value)
{
	fromJson(std::move(json.get("start")), value.start);
	fromJson(std::move(json.get("deleteCount")), value.deleteCount);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, SemanticTokensEdit& value)
{
	auto& obj = json.object();
	semanticTokensEditFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensEdit>() -> const char**
{
	static const char* properties[] = {
		"start",
		"deleteCount",
		nullptr
	};
	return properties;
}

static void semanticTokensDeltaFromJson(json::Object& json, SemanticTokensDelta& value)
{
	fromJson(std::move(json.get("edits")), value.edits);
	if(auto* const v = json.find("resultId"))
		fromJson(std::move(*v), value.resultId);
}

void fromJson(json::Value&& json, SemanticTokensDelta& value)
{
	auto& obj = json.object();
	semanticTokensDeltaFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensDelta>() -> const char**
{
	static const char* properties[] = {
		"edits",
		nullptr
	};
	return properties;
}

static void semanticTokensDeltaPartialResultFromJson(json::Object& json, SemanticTokensDeltaPartialResult& value)
{
	fromJson(std::move(json.get("edits")), value.edits);
}

void fromJson(json::Value&& json, SemanticTokensDeltaPartialResult& value)
{
	auto& obj = json.object();
	semanticTokensDeltaPartialResultFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensDeltaPartialResult>() -> const char**
{
	static const char* properties[] = {
		"edits",
		nullptr
	};
	return properties;
}

static void semanticTokensRangeParamsFromJson(json::Object& json, SemanticTokensRangeParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("range")), value.range);
}

void fromJson(json::Value&& json, SemanticTokensRangeParams& value)
{
	auto& obj = json.object();
	semanticTokensRangeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensRangeParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"range",
		nullptr
	};
	return properties;
}

static void showDocumentParamsFromJson(json::Object& json, ShowDocumentParams& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	if(auto* const v = json.find("external"))
		fromJson(std::move(*v), value.external);
	if(auto* const v = json.find("takeFocus"))
		fromJson(std::move(*v), value.takeFocus);
	if(auto* const v = json.find("selection"))
		fromJson(std::move(*v), value.selection);
}

void fromJson(json::Value&& json, ShowDocumentParams& value)
{
	auto& obj = json.object();
	showDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ShowDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void showDocumentResultFromJson(json::Object& json, ShowDocumentResult& value)
{
	fromJson(std::move(json.get("success")), value.success);
}

void fromJson(json::Value&& json, ShowDocumentResult& value)
{
	auto& obj = json.object();
	showDocumentResultFromJson(obj, value);
}

template<>
auto requiredProperties<ShowDocumentResult>() -> const char**
{
	static const char* properties[] = {
		"success",
		nullptr
	};
	return properties;
}

static void linkedEditingRangeParamsFromJson(json::Object& json, LinkedEditingRangeParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, LinkedEditingRangeParams& value)
{
	auto& obj = json.object();
	linkedEditingRangeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<LinkedEditingRangeParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void linkedEditingRangesFromJson(json::Object& json, LinkedEditingRanges& value)
{
	fromJson(std::move(json.get("ranges")), value.ranges);
	if(auto* const v = json.find("wordPattern"))
		fromJson(std::move(*v), value.wordPattern);
}

void fromJson(json::Value&& json, LinkedEditingRanges& value)
{
	auto& obj = json.object();
	linkedEditingRangesFromJson(obj, value);
}

template<>
auto requiredProperties<LinkedEditingRanges>() -> const char**
{
	static const char* properties[] = {
		"ranges",
		nullptr
	};
	return properties;
}

static void linkedEditingRangeOptionsFromJson(json::Object& json, LinkedEditingRangeOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, LinkedEditingRangeOptions& value)
{
	auto& obj = json.object();
	linkedEditingRangeOptionsFromJson(obj, value);
}

static void linkedEditingRangeRegistrationOptionsFromJson(json::Object& json, LinkedEditingRangeRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	linkedEditingRangeOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, LinkedEditingRangeRegistrationOptions& value)
{
	auto& obj = json.object();
	linkedEditingRangeRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<LinkedEditingRangeRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void fileCreateFromJson(json::Object& json, FileCreate& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, FileCreate& value)
{
	auto& obj = json.object();
	fileCreateFromJson(obj, value);
}

template<>
auto requiredProperties<FileCreate>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void createFilesParamsFromJson(json::Object& json, CreateFilesParams& value)
{
	fromJson(std::move(json.get("files")), value.files);
}

void fromJson(json::Value&& json, CreateFilesParams& value)
{
	auto& obj = json.object();
	createFilesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CreateFilesParams>() -> const char**
{
	static const char* properties[] = {
		"files",
		nullptr
	};
	return properties;
}

static void optionalVersionedTextDocumentIdentifierFromJson(json::Object& json, OptionalVersionedTextDocumentIdentifier& value)
{
	textDocumentIdentifierFromJson(json, value);
	fromJson(std::move(json.get("version")), value.version);
}

void fromJson(json::Value&& json, OptionalVersionedTextDocumentIdentifier& value)
{
	auto& obj = json.object();
	optionalVersionedTextDocumentIdentifierFromJson(obj, value);
}

template<>
auto requiredProperties<OptionalVersionedTextDocumentIdentifier>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"version",
		nullptr
	};
	return properties;
}

static void annotatedTextEditFromJson(json::Object& json, AnnotatedTextEdit& value)
{
	textEditFromJson(json, value);
	fromJson(std::move(json.get("annotationId")), value.annotationId);
}

void fromJson(json::Value&& json, AnnotatedTextEdit& value)
{
	auto& obj = json.object();
	annotatedTextEditFromJson(obj, value);
}

template<>
auto requiredProperties<AnnotatedTextEdit>() -> const char**
{
	static const char* properties[] = {
		"range",
		"newText",
		"annotationId",
		nullptr
	};
	return properties;
}

static void stringValueFromJson(json::Object& json, StringValue& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "snippet")
		throw json::TypeError("Invalid value for literal property 'kind'");
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, StringValue& value)
{
	auto& obj = json.object();
	stringValueFromJson(obj, value);
}

template<>
auto requiredProperties<StringValue>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"value",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<StringValue>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "snippet"},
		{nullptr, {}}
	};
	return properties;
}

static void snippetTextEditFromJson(json::Object& json, SnippetTextEdit& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("snippet")), value.snippet);
	if(auto* const v = json.find("annotationId"))
		fromJson(std::move(*v), value.annotationId);
}

void fromJson(json::Value&& json, SnippetTextEdit& value)
{
	auto& obj = json.object();
	snippetTextEditFromJson(obj, value);
}

template<>
auto requiredProperties<SnippetTextEdit>() -> const char**
{
	static const char* properties[] = {
		"range",
		"snippet",
		nullptr
	};
	return properties;
}

static void textDocumentEditFromJson(json::Object& json, TextDocumentEdit& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("edits")), value.edits);
}

void fromJson(json::Value&& json, TextDocumentEdit& value)
{
	auto& obj = json.object();
	textDocumentEditFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentEdit>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"edits",
		nullptr
	};
	return properties;
}

static void resourceOperationFromJson(json::Object& json, ResourceOperation& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(auto* const v = json.find("annotationId"))
		fromJson(std::move(*v), value.annotationId);
}

void fromJson(json::Value&& json, ResourceOperation& value)
{
	auto& obj = json.object();
	resourceOperationFromJson(obj, value);
}

template<>
auto requiredProperties<ResourceOperation>() -> const char**
{
	static const char* properties[] = {
		"kind",
		nullptr
	};
	return properties;
}

static void createFileOptionsFromJson(json::Object& json, CreateFileOptions& value)
{
	if(auto* const v = json.find("overwrite"))
		fromJson(std::move(*v), value.overwrite);
	if(auto* const v = json.find("ignoreIfExists"))
		fromJson(std::move(*v), value.ignoreIfExists);
}

void fromJson(json::Value&& json, CreateFileOptions& value)
{
	auto& obj = json.object();
	createFileOptionsFromJson(obj, value);
}

static void createFileFromJson(json::Object& json, CreateFile& value)
{
	resourceOperationFromJson(json, value);
	fromJson(std::move(json.get("uri")), value.uri);
	if(auto* const v = json.find("options"))
		fromJson(std::move(*v), value.options);
}

void fromJson(json::Value&& json, CreateFile& value)
{
	auto& obj = json.object();
	createFileFromJson(obj, value);
}

template<>
auto requiredProperties<CreateFile>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"kind",
		"uri",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<CreateFile>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "create"},
		{nullptr, {}}
	};
	return properties;
}

static void renameFileOptionsFromJson(json::Object& json, RenameFileOptions& value)
{
	if(auto* const v = json.find("overwrite"))
		fromJson(std::move(*v), value.overwrite);
	if(auto* const v = json.find("ignoreIfExists"))
		fromJson(std::move(*v), value.ignoreIfExists);
}

void fromJson(json::Value&& json, RenameFileOptions& value)
{
	auto& obj = json.object();
	renameFileOptionsFromJson(obj, value);
}

static void renameFileFromJson(json::Object& json, RenameFile& value)
{
	resourceOperationFromJson(json, value);
	fromJson(std::move(json.get("oldUri")), value.oldUri);
	fromJson(std::move(json.get("newUri")), value.newUri);
	if(auto* const v = json.find("options"))
		fromJson(std::move(*v), value.options);
}

void fromJson(json::Value&& json, RenameFile& value)
{
	auto& obj = json.object();
	renameFileFromJson(obj, value);
}

template<>
auto requiredProperties<RenameFile>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"kind",
		"oldUri",
		"newUri",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<RenameFile>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "rename"},
		{nullptr, {}}
	};
	return properties;
}

static void deleteFileOptionsFromJson(json::Object& json, DeleteFileOptions& value)
{
	if(auto* const v = json.find("recursive"))
		fromJson(std::move(*v), value.recursive);
	if(auto* const v = json.find("ignoreIfNotExists"))
		fromJson(std::move(*v), value.ignoreIfNotExists);
}

void fromJson(json::Value&& json, DeleteFileOptions& value)
{
	auto& obj = json.object();
	deleteFileOptionsFromJson(obj, value);
}

static void deleteFileFromJson(json::Object& json, DeleteFile& value)
{
	resourceOperationFromJson(json, value);
	fromJson(std::move(json.get("uri")), value.uri);
	if(auto* const v = json.find("options"))
		fromJson(std::move(*v), value.options);
}

void fromJson(json::Value&& json, DeleteFile& value)
{
	auto& obj = json.object();
	deleteFileFromJson(obj, value);
}

template<>
auto requiredProperties<DeleteFile>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"kind",
		"uri",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<DeleteFile>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "delete"},
		{nullptr, {}}
	};
	return properties;
}

static void changeAnnotationFromJson(json::Object& json, ChangeAnnotation& value)
{
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("needsConfirmation"))
		fromJson(std::move(*v), value.needsConfirmation);
	if(auto* const v = json.find("description"))
		fromJson(std::move(*v), value.description);
}

void fromJson(json::Value&& json, ChangeAnnotation& value)
{
	auto& obj = json.object();
	changeAnnotationFromJson(obj, value);
}

template<>
auto requiredProperties<ChangeAnnotation>() -> const char**
{
	static const char* properties[] = {
		"label",
		nullptr
	};
	return properties;
}

static void workspaceEditFromJson(json::Object& json, WorkspaceEdit& value)
{
	if(auto* const v = json.find("changes"))
		fromJson(std::move(*v), value.changes);
	if(auto* const v = json.find("documentChanges"))
		fromJson(std::move(*v), value.documentChanges);
	if(auto* const v = json.find("changeAnnotations"))
		fromJson(std::move(*v), value.changeAnnotations);
}

void fromJson(json::Value&& json, WorkspaceEdit& value)
{
	auto& obj = json.object();
	workspaceEditFromJson(obj, value);
}

static void fileOperationPatternOptionsFromJson(json::Object& json, FileOperationPatternOptions& value)
{
	if(auto* const v = json.find("ignoreCase"))
		fromJson(std::move(*v), value.ignoreCase);
}

void fromJson(json::Value&& json, FileOperationPatternOptions& value)
{
	auto& obj = json.object();
	fileOperationPatternOptionsFromJson(obj, value);
}

static void fileOperationPatternFromJson(json::Object& json, FileOperationPattern& value)
{
	fromJson(std::move(json.get("glob")), value.glob);
	if(auto* const v = json.find("matches"))
		fromJson(std::move(*v), value.matches);
	if(auto* const v = json.find("options"))
		fromJson(std::move(*v), value.options);
}

void fromJson(json::Value&& json, FileOperationPattern& value)
{
	auto& obj = json.object();
	fileOperationPatternFromJson(obj, value);
}

template<>
auto requiredProperties<FileOperationPattern>() -> const char**
{
	static const char* properties[] = {
		"glob",
		nullptr
	};
	return properties;
}

static void fileOperationFilterFromJson(json::Object& json, FileOperationFilter& value)
{
	fromJson(std::move(json.get("pattern")), value.pattern);
	if(auto* const v = json.find("scheme"))
		fromJson(std::move(*v), value.scheme);
}

void fromJson(json::Value&& json, FileOperationFilter& value)
{
	auto& obj = json.object();
	fileOperationFilterFromJson(obj, value);
}

template<>
auto requiredProperties<FileOperationFilter>() -> const char**
{
	static const char* properties[] = {
		"pattern",
		nullptr
	};
	return properties;
}

static void fileOperationRegistrationOptionsFromJson(json::Object& json, FileOperationRegistrationOptions& value)
{
	fromJson(std::move(json.get("filters")), value.filters);
}

void fromJson(json::Value&& json, FileOperationRegistrationOptions& value)
{
	auto& obj = json.object();
	fileOperationRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<FileOperationRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"filters",
		nullptr
	};
	return properties;
}

static void fileRenameFromJson(json::Object& json, FileRename& value)
{
	fromJson(std::move(json.get("oldUri")), value.oldUri);
	fromJson(std::move(json.get("newUri")), value.newUri);
}

void fromJson(json::Value&& json, FileRename& value)
{
	auto& obj = json.object();
	fileRenameFromJson(obj, value);
}

template<>
auto requiredProperties<FileRename>() -> const char**
{
	static const char* properties[] = {
		"oldUri",
		"newUri",
		nullptr
	};
	return properties;
}

static void renameFilesParamsFromJson(json::Object& json, RenameFilesParams& value)
{
	fromJson(std::move(json.get("files")), value.files);
}

void fromJson(json::Value&& json, RenameFilesParams& value)
{
	auto& obj = json.object();
	renameFilesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<RenameFilesParams>() -> const char**
{
	static const char* properties[] = {
		"files",
		nullptr
	};
	return properties;
}

static void fileDeleteFromJson(json::Object& json, FileDelete& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, FileDelete& value)
{
	auto& obj = json.object();
	fileDeleteFromJson(obj, value);
}

template<>
auto requiredProperties<FileDelete>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void deleteFilesParamsFromJson(json::Object& json, DeleteFilesParams& value)
{
	fromJson(std::move(json.get("files")), value.files);
}

void fromJson(json::Value&& json, DeleteFilesParams& value)
{
	auto& obj = json.object();
	deleteFilesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DeleteFilesParams>() -> const char**
{
	static const char* properties[] = {
		"files",
		nullptr
	};
	return properties;
}

static void monikerParamsFromJson(json::Object& json, MonikerParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, MonikerParams& value)
{
	auto& obj = json.object();
	monikerParamsFromJson(obj, value);
}

template<>
auto requiredProperties<MonikerParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void monikerFromJson(json::Object& json, Moniker& value)
{
	fromJson(std::move(json.get("scheme")), value.scheme);
	fromJson(std::move(json.get("identifier")), value.identifier);
	fromJson(std::move(json.get("unique")), value.unique);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
}

void fromJson(json::Value&& json, Moniker& value)
{
	auto& obj = json.object();
	monikerFromJson(obj, value);
}

template<>
auto requiredProperties<Moniker>() -> const char**
{
	static const char* properties[] = {
		"scheme",
		"identifier",
		"unique",
		nullptr
	};
	return properties;
}

static void monikerOptionsFromJson(json::Object& json, MonikerOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, MonikerOptions& value)
{
	auto& obj = json.object();
	monikerOptionsFromJson(obj, value);
}

static void monikerRegistrationOptionsFromJson(json::Object& json, MonikerRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	monikerOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, MonikerRegistrationOptions& value)
{
	auto& obj = json.object();
	monikerRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<MonikerRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void typeHierarchyPrepareParamsFromJson(json::Object& json, TypeHierarchyPrepareParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, TypeHierarchyPrepareParams& value)
{
	auto& obj = json.object();
	typeHierarchyPrepareParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeHierarchyPrepareParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void typeHierarchyItemFromJson(json::Object& json, TypeHierarchyItem& value)
{
	fromJson(std::move(json.get("name")), value.name);
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("selectionRange")), value.selectionRange);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("detail"))
		fromJson(std::move(*v), value.detail);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, TypeHierarchyItem& value)
{
	auto& obj = json.object();
	typeHierarchyItemFromJson(obj, value);
}

template<>
auto requiredProperties<TypeHierarchyItem>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		"uri",
		"range",
		"selectionRange",
		nullptr
	};
	return properties;
}

static void typeHierarchyOptionsFromJson(json::Object& json, TypeHierarchyOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, TypeHierarchyOptions& value)
{
	auto& obj = json.object();
	typeHierarchyOptionsFromJson(obj, value);
}

static void typeHierarchyRegistrationOptionsFromJson(json::Object& json, TypeHierarchyRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	typeHierarchyOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, TypeHierarchyRegistrationOptions& value)
{
	auto& obj = json.object();
	typeHierarchyRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeHierarchyRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void typeHierarchySupertypesParamsFromJson(json::Object& json, TypeHierarchySupertypesParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("item")), value.item);
}

void fromJson(json::Value&& json, TypeHierarchySupertypesParams& value)
{
	auto& obj = json.object();
	typeHierarchySupertypesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeHierarchySupertypesParams>() -> const char**
{
	static const char* properties[] = {
		"item",
		nullptr
	};
	return properties;
}

static void typeHierarchySubtypesParamsFromJson(json::Object& json, TypeHierarchySubtypesParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("item")), value.item);
}

void fromJson(json::Value&& json, TypeHierarchySubtypesParams& value)
{
	auto& obj = json.object();
	typeHierarchySubtypesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TypeHierarchySubtypesParams>() -> const char**
{
	static const char* properties[] = {
		"item",
		nullptr
	};
	return properties;
}

static void inlineValueContextFromJson(json::Object& json, InlineValueContext& value)
{
	fromJson(std::move(json.get("frameId")), value.frameId);
	fromJson(std::move(json.get("stoppedLocation")), value.stoppedLocation);
}

void fromJson(json::Value&& json, InlineValueContext& value)
{
	auto& obj = json.object();
	inlineValueContextFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueContext>() -> const char**
{
	static const char* properties[] = {
		"frameId",
		"stoppedLocation",
		nullptr
	};
	return properties;
}

static void inlineValueParamsFromJson(json::Object& json, InlineValueParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("context")), value.context);
}

void fromJson(json::Value&& json, InlineValueParams& value)
{
	auto& obj = json.object();
	inlineValueParamsFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"range",
		"context",
		nullptr
	};
	return properties;
}

static void inlineValueOptionsFromJson(json::Object& json, InlineValueOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, InlineValueOptions& value)
{
	auto& obj = json.object();
	inlineValueOptionsFromJson(obj, value);
}

static void inlineValueRegistrationOptionsFromJson(json::Object& json, InlineValueRegistrationOptions& value)
{
	inlineValueOptionsFromJson(json, value);
	textDocumentRegistrationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, InlineValueRegistrationOptions& value)
{
	auto& obj = json.object();
	inlineValueRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void inlayHintParamsFromJson(json::Object& json, InlayHintParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("range")), value.range);
}

void fromJson(json::Value&& json, InlayHintParams& value)
{
	auto& obj = json.object();
	inlayHintParamsFromJson(obj, value);
}

template<>
auto requiredProperties<InlayHintParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"range",
		nullptr
	};
	return properties;
}

static void markupContentFromJson(json::Object& json, MarkupContent& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, MarkupContent& value)
{
	auto& obj = json.object();
	markupContentFromJson(obj, value);
}

template<>
auto requiredProperties<MarkupContent>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"value",
		nullptr
	};
	return properties;
}

static void commandFromJson(json::Object& json, Command& value)
{
	fromJson(std::move(json.get("title")), value.title);
	fromJson(std::move(json.get("command")), value.command);
	if(auto* const v = json.find("tooltip"))
		fromJson(std::move(*v), value.tooltip);
	if(auto* const v = json.find("arguments"))
		fromJson(std::move(*v), value.arguments);
}

void fromJson(json::Value&& json, Command& value)
{
	auto& obj = json.object();
	commandFromJson(obj, value);
}

template<>
auto requiredProperties<Command>() -> const char**
{
	static const char* properties[] = {
		"title",
		"command",
		nullptr
	};
	return properties;
}

static void inlayHintLabelPartFromJson(json::Object& json, InlayHintLabelPart& value)
{
	fromJson(std::move(json.get("value")), value.value);
	if(auto* const v = json.find("tooltip"))
		fromJson(std::move(*v), value.tooltip);
	if(auto* const v = json.find("location"))
		fromJson(std::move(*v), value.location);
	if(auto* const v = json.find("command"))
		fromJson(std::move(*v), value.command);
}

void fromJson(json::Value&& json, InlayHintLabelPart& value)
{
	auto& obj = json.object();
	inlayHintLabelPartFromJson(obj, value);
}

template<>
auto requiredProperties<InlayHintLabelPart>() -> const char**
{
	static const char* properties[] = {
		"value",
		nullptr
	};
	return properties;
}

static void inlayHintFromJson(json::Object& json, InlayHint& value)
{
	fromJson(std::move(json.get("position")), value.position);
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
	if(auto* const v = json.find("textEdits"))
		fromJson(std::move(*v), value.textEdits);
	if(auto* const v = json.find("tooltip"))
		fromJson(std::move(*v), value.tooltip);
	if(auto* const v = json.find("paddingLeft"))
		fromJson(std::move(*v), value.paddingLeft);
	if(auto* const v = json.find("paddingRight"))
		fromJson(std::move(*v), value.paddingRight);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, InlayHint& value)
{
	auto& obj = json.object();
	inlayHintFromJson(obj, value);
}

template<>
auto requiredProperties<InlayHint>() -> const char**
{
	static const char* properties[] = {
		"position",
		"label",
		nullptr
	};
	return properties;
}

static void inlayHintOptionsFromJson(json::Object& json, InlayHintOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
}

void fromJson(json::Value&& json, InlayHintOptions& value)
{
	auto& obj = json.object();
	inlayHintOptionsFromJson(obj, value);
}

static void inlayHintRegistrationOptionsFromJson(json::Object& json, InlayHintRegistrationOptions& value)
{
	inlayHintOptionsFromJson(json, value);
	textDocumentRegistrationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, InlayHintRegistrationOptions& value)
{
	auto& obj = json.object();
	inlayHintRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<InlayHintRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentDiagnosticParamsFromJson(json::Object& json, DocumentDiagnosticParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	if(auto* const v = json.find("identifier"))
		fromJson(std::move(*v), value.identifier);
	if(auto* const v = json.find("previousResultId"))
		fromJson(std::move(*v), value.previousResultId);
}

void fromJson(json::Value&& json, DocumentDiagnosticParams& value)
{
	auto& obj = json.object();
	documentDiagnosticParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentDiagnosticParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void diagnosticServerCancellationDataFromJson(json::Object& json, DiagnosticServerCancellationData& value)
{
	fromJson(std::move(json.get("retriggerRequest")), value.retriggerRequest);
}

void fromJson(json::Value&& json, DiagnosticServerCancellationData& value)
{
	auto& obj = json.object();
	diagnosticServerCancellationDataFromJson(obj, value);
}

template<>
auto requiredProperties<DiagnosticServerCancellationData>() -> const char**
{
	static const char* properties[] = {
		"retriggerRequest",
		nullptr
	};
	return properties;
}

static void diagnosticOptionsFromJson(json::Object& json, DiagnosticOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	fromJson(std::move(json.get("interFileDependencies")), value.interFileDependencies);
	fromJson(std::move(json.get("workspaceDiagnostics")), value.workspaceDiagnostics);
	if(auto* const v = json.find("identifier"))
		fromJson(std::move(*v), value.identifier);
}

void fromJson(json::Value&& json, DiagnosticOptions& value)
{
	auto& obj = json.object();
	diagnosticOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DiagnosticOptions>() -> const char**
{
	static const char* properties[] = {
		"interFileDependencies",
		"workspaceDiagnostics",
		nullptr
	};
	return properties;
}

static void diagnosticRegistrationOptionsFromJson(json::Object& json, DiagnosticRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	diagnosticOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, DiagnosticRegistrationOptions& value)
{
	auto& obj = json.object();
	diagnosticRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DiagnosticRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		"interFileDependencies",
		"workspaceDiagnostics",
		nullptr
	};
	return properties;
}

static void previousResultIdFromJson(json::Object& json, PreviousResultId& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, PreviousResultId& value)
{
	auto& obj = json.object();
	previousResultIdFromJson(obj, value);
}

template<>
auto requiredProperties<PreviousResultId>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"value",
		nullptr
	};
	return properties;
}

static void workspaceDiagnosticParamsFromJson(json::Object& json, WorkspaceDiagnosticParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("previousResultIds")), value.previousResultIds);
	if(auto* const v = json.find("identifier"))
		fromJson(std::move(*v), value.identifier);
}

void fromJson(json::Value&& json, WorkspaceDiagnosticParams& value)
{
	auto& obj = json.object();
	workspaceDiagnosticParamsFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceDiagnosticParams>() -> const char**
{
	static const char* properties[] = {
		"previousResultIds",
		nullptr
	};
	return properties;
}

static void codeDescriptionFromJson(json::Object& json, CodeDescription& value)
{
	fromJson(std::move(json.get("href")), value.href);
}

void fromJson(json::Value&& json, CodeDescription& value)
{
	auto& obj = json.object();
	codeDescriptionFromJson(obj, value);
}

template<>
auto requiredProperties<CodeDescription>() -> const char**
{
	static const char* properties[] = {
		"href",
		nullptr
	};
	return properties;
}

static void diagnosticRelatedInformationFromJson(json::Object& json, DiagnosticRelatedInformation& value)
{
	fromJson(std::move(json.get("location")), value.location);
	fromJson(std::move(json.get("message")), value.message);
}

void fromJson(json::Value&& json, DiagnosticRelatedInformation& value)
{
	auto& obj = json.object();
	diagnosticRelatedInformationFromJson(obj, value);
}

template<>
auto requiredProperties<DiagnosticRelatedInformation>() -> const char**
{
	static const char* properties[] = {
		"location",
		"message",
		nullptr
	};
	return properties;
}

static void diagnosticFromJson(json::Object& json, Diagnostic& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("message")), value.message);
	if(auto* const v = json.find("severity"))
		fromJson(std::move(*v), value.severity);
	if(auto* const v = json.find("code"))
		fromJson(std::move(*v), value.code);
	if(auto* const v = json.find("codeDescription"))
		fromJson(std::move(*v), value.codeDescription);
	if(auto* const v = json.find("source"))
		fromJson(std::move(*v), value.source);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("relatedInformation"))
		fromJson(std::move(*v), value.relatedInformation);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, Diagnostic& value)
{
	auto& obj = json.object();
	diagnosticFromJson(obj, value);
}

template<>
auto requiredProperties<Diagnostic>() -> const char**
{
	static const char* properties[] = {
		"range",
		"message",
		nullptr
	};
	return properties;
}

static void fullDocumentDiagnosticReportFromJson(json::Object& json, FullDocumentDiagnosticReport& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "full")
		throw json::TypeError("Invalid value for literal property 'kind'");
	fromJson(std::move(json.get("items")), value.items);
	if(auto* const v = json.find("resultId"))
		fromJson(std::move(*v), value.resultId);
}

void fromJson(json::Value&& json, FullDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	fullDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<FullDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"items",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<FullDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "full"},
		{nullptr, {}}
	};
	return properties;
}

static void workspaceFullDocumentDiagnosticReportFromJson(json::Object& json, WorkspaceFullDocumentDiagnosticReport& value)
{
	fullDocumentDiagnosticReportFromJson(json, value);
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("version")), value.version);
}

void fromJson(json::Value&& json, WorkspaceFullDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	workspaceFullDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceFullDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"items",
		"uri",
		"version",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<WorkspaceFullDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "full"},
		{nullptr, {}}
	};
	return properties;
}

static void unchangedDocumentDiagnosticReportFromJson(json::Object& json, UnchangedDocumentDiagnosticReport& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "unchanged")
		throw json::TypeError("Invalid value for literal property 'kind'");
	fromJson(std::move(json.get("resultId")), value.resultId);
}

void fromJson(json::Value&& json, UnchangedDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	unchangedDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<UnchangedDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"resultId",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<UnchangedDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "unchanged"},
		{nullptr, {}}
	};
	return properties;
}

static void workspaceUnchangedDocumentDiagnosticReportFromJson(json::Object& json, WorkspaceUnchangedDocumentDiagnosticReport& value)
{
	unchangedDocumentDiagnosticReportFromJson(json, value);
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("version")), value.version);
}

void fromJson(json::Value&& json, WorkspaceUnchangedDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	workspaceUnchangedDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceUnchangedDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"resultId",
		"uri",
		"version",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<WorkspaceUnchangedDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "unchanged"},
		{nullptr, {}}
	};
	return properties;
}

static void workspaceDiagnosticReportFromJson(json::Object& json, WorkspaceDiagnosticReport& value)
{
	fromJson(std::move(json.get("items")), value.items);
}

void fromJson(json::Value&& json, WorkspaceDiagnosticReport& value)
{
	auto& obj = json.object();
	workspaceDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"items",
		nullptr
	};
	return properties;
}

static void workspaceDiagnosticReportPartialResultFromJson(json::Object& json, WorkspaceDiagnosticReportPartialResult& value)
{
	fromJson(std::move(json.get("items")), value.items);
}

void fromJson(json::Value&& json, WorkspaceDiagnosticReportPartialResult& value)
{
	auto& obj = json.object();
	workspaceDiagnosticReportPartialResultFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceDiagnosticReportPartialResult>() -> const char**
{
	static const char* properties[] = {
		"items",
		nullptr
	};
	return properties;
}

static void executionSummaryFromJson(json::Object& json, ExecutionSummary& value)
{
	fromJson(std::move(json.get("executionOrder")), value.executionOrder);
	if(auto* const v = json.find("success"))
		fromJson(std::move(*v), value.success);
}

void fromJson(json::Value&& json, ExecutionSummary& value)
{
	auto& obj = json.object();
	executionSummaryFromJson(obj, value);
}

template<>
auto requiredProperties<ExecutionSummary>() -> const char**
{
	static const char* properties[] = {
		"executionOrder",
		nullptr
	};
	return properties;
}

static void notebookCellFromJson(json::Object& json, NotebookCell& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("document")), value.document);
	if(auto* const v = json.find("metadata"))
		fromJson(std::move(*v), value.metadata);
	if(auto* const v = json.find("executionSummary"))
		fromJson(std::move(*v), value.executionSummary);
}

void fromJson(json::Value&& json, NotebookCell& value)
{
	auto& obj = json.object();
	notebookCellFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookCell>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"document",
		nullptr
	};
	return properties;
}

static void notebookDocumentFromJson(json::Object& json, NotebookDocument& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("notebookType")), value.notebookType);
	fromJson(std::move(json.get("version")), value.version);
	fromJson(std::move(json.get("cells")), value.cells);
	if(auto* const v = json.find("metadata"))
		fromJson(std::move(*v), value.metadata);
}

void fromJson(json::Value&& json, NotebookDocument& value)
{
	auto& obj = json.object();
	notebookDocumentFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocument>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"notebookType",
		"version",
		"cells",
		nullptr
	};
	return properties;
}

static void textDocumentItemFromJson(json::Object& json, TextDocumentItem& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("languageId")), value.languageId);
	fromJson(std::move(json.get("version")), value.version);
	fromJson(std::move(json.get("text")), value.text);
}

void fromJson(json::Value&& json, TextDocumentItem& value)
{
	auto& obj = json.object();
	textDocumentItemFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentItem>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"languageId",
		"version",
		"text",
		nullptr
	};
	return properties;
}

static void didOpenNotebookDocumentParamsFromJson(json::Object& json, DidOpenNotebookDocumentParams& value)
{
	fromJson(std::move(json.get("notebookDocument")), value.notebookDocument);
	fromJson(std::move(json.get("cellTextDocuments")), value.cellTextDocuments);
}

void fromJson(json::Value&& json, DidOpenNotebookDocumentParams& value)
{
	auto& obj = json.object();
	didOpenNotebookDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidOpenNotebookDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"notebookDocument",
		"cellTextDocuments",
		nullptr
	};
	return properties;
}

static void notebookCellLanguageFromJson(json::Object& json, NotebookCellLanguage& value)
{
	fromJson(std::move(json.get("language")), value.language);
}

void fromJson(json::Value&& json, NotebookCellLanguage& value)
{
	auto& obj = json.object();
	notebookCellLanguageFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookCellLanguage>() -> const char**
{
	static const char* properties[] = {
		"language",
		nullptr
	};
	return properties;
}

static void notebookDocumentFilterWithNotebookFromJson(json::Object& json, NotebookDocumentFilterWithNotebook& value)
{
	fromJson(std::move(json.get("notebook")), value.notebook);
	if(auto* const v = json.find("cells"))
		fromJson(std::move(*v), value.cells);
}

void fromJson(json::Value&& json, NotebookDocumentFilterWithNotebook& value)
{
	auto& obj = json.object();
	notebookDocumentFilterWithNotebookFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentFilterWithNotebook>() -> const char**
{
	static const char* properties[] = {
		"notebook",
		nullptr
	};
	return properties;
}

static void notebookDocumentFilterWithCellsFromJson(json::Object& json, NotebookDocumentFilterWithCells& value)
{
	fromJson(std::move(json.get("cells")), value.cells);
	if(auto* const v = json.find("notebook"))
		fromJson(std::move(*v), value.notebook);
}

void fromJson(json::Value&& json, NotebookDocumentFilterWithCells& value)
{
	auto& obj = json.object();
	notebookDocumentFilterWithCellsFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentFilterWithCells>() -> const char**
{
	static const char* properties[] = {
		"cells",
		nullptr
	};
	return properties;
}

static void notebookDocumentSyncOptionsFromJson(json::Object& json, NotebookDocumentSyncOptions& value)
{
	fromJson(std::move(json.get("notebookSelector")), value.notebookSelector);
	if(auto* const v = json.find("save"))
		fromJson(std::move(*v), value.save);
}

void fromJson(json::Value&& json, NotebookDocumentSyncOptions& value)
{
	auto& obj = json.object();
	notebookDocumentSyncOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentSyncOptions>() -> const char**
{
	static const char* properties[] = {
		"notebookSelector",
		nullptr
	};
	return properties;
}

static void notebookDocumentSyncRegistrationOptionsFromJson(json::Object& json, NotebookDocumentSyncRegistrationOptions& value)
{
	notebookDocumentSyncOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, NotebookDocumentSyncRegistrationOptions& value)
{
	auto& obj = json.object();
	notebookDocumentSyncRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentSyncRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"notebookSelector",
		nullptr
	};
	return properties;
}

static void versionedNotebookDocumentIdentifierFromJson(json::Object& json, VersionedNotebookDocumentIdentifier& value)
{
	fromJson(std::move(json.get("version")), value.version);
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, VersionedNotebookDocumentIdentifier& value)
{
	auto& obj = json.object();
	versionedNotebookDocumentIdentifierFromJson(obj, value);
}

template<>
auto requiredProperties<VersionedNotebookDocumentIdentifier>() -> const char**
{
	static const char* properties[] = {
		"version",
		"uri",
		nullptr
	};
	return properties;
}

static void notebookCellArrayChangeFromJson(json::Object& json, NotebookCellArrayChange& value)
{
	fromJson(std::move(json.get("start")), value.start);
	fromJson(std::move(json.get("deleteCount")), value.deleteCount);
	if(auto* const v = json.find("cells"))
		fromJson(std::move(*v), value.cells);
}

void fromJson(json::Value&& json, NotebookCellArrayChange& value)
{
	auto& obj = json.object();
	notebookCellArrayChangeFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookCellArrayChange>() -> const char**
{
	static const char* properties[] = {
		"start",
		"deleteCount",
		nullptr
	};
	return properties;
}

static void notebookDocumentCellChangeStructureFromJson(json::Object& json, NotebookDocumentCellChangeStructure& value)
{
	fromJson(std::move(json.get("array")), value.array);
	if(auto* const v = json.find("didOpen"))
		fromJson(std::move(*v), value.didOpen);
	if(auto* const v = json.find("didClose"))
		fromJson(std::move(*v), value.didClose);
}

void fromJson(json::Value&& json, NotebookDocumentCellChangeStructure& value)
{
	auto& obj = json.object();
	notebookDocumentCellChangeStructureFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentCellChangeStructure>() -> const char**
{
	static const char* properties[] = {
		"array",
		nullptr
	};
	return properties;
}

static void versionedTextDocumentIdentifierFromJson(json::Object& json, VersionedTextDocumentIdentifier& value)
{
	textDocumentIdentifierFromJson(json, value);
	fromJson(std::move(json.get("version")), value.version);
}

void fromJson(json::Value&& json, VersionedTextDocumentIdentifier& value)
{
	auto& obj = json.object();
	versionedTextDocumentIdentifierFromJson(obj, value);
}

template<>
auto requiredProperties<VersionedTextDocumentIdentifier>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"version",
		nullptr
	};
	return properties;
}

static void textDocumentContentChangePartialFromJson(json::Object& json, TextDocumentContentChangePartial& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("text")), value.text);
	if(auto* const v = json.find("rangeLength"))
		fromJson(std::move(*v), value.rangeLength);
}

void fromJson(json::Value&& json, TextDocumentContentChangePartial& value)
{
	auto& obj = json.object();
	textDocumentContentChangePartialFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentChangePartial>() -> const char**
{
	static const char* properties[] = {
		"range",
		"text",
		nullptr
	};
	return properties;
}

static void textDocumentContentChangeWholeDocumentFromJson(json::Object& json, TextDocumentContentChangeWholeDocument& value)
{
	fromJson(std::move(json.get("text")), value.text);
}

void fromJson(json::Value&& json, TextDocumentContentChangeWholeDocument& value)
{
	auto& obj = json.object();
	textDocumentContentChangeWholeDocumentFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentChangeWholeDocument>() -> const char**
{
	static const char* properties[] = {
		"text",
		nullptr
	};
	return properties;
}

static void notebookDocumentCellContentChangesFromJson(json::Object& json, NotebookDocumentCellContentChanges& value)
{
	fromJson(std::move(json.get("document")), value.document);
	fromJson(std::move(json.get("changes")), value.changes);
}

void fromJson(json::Value&& json, NotebookDocumentCellContentChanges& value)
{
	auto& obj = json.object();
	notebookDocumentCellContentChangesFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentCellContentChanges>() -> const char**
{
	static const char* properties[] = {
		"document",
		"changes",
		nullptr
	};
	return properties;
}

static void notebookDocumentCellChangesFromJson(json::Object& json, NotebookDocumentCellChanges& value)
{
	if(auto* const v = json.find("structure"))
		fromJson(std::move(*v), value.structure);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
	if(auto* const v = json.find("textContent"))
		fromJson(std::move(*v), value.textContent);
}

void fromJson(json::Value&& json, NotebookDocumentCellChanges& value)
{
	auto& obj = json.object();
	notebookDocumentCellChangesFromJson(obj, value);
}

static void notebookDocumentChangeEventFromJson(json::Object& json, NotebookDocumentChangeEvent& value)
{
	if(auto* const v = json.find("metadata"))
		fromJson(std::move(*v), value.metadata);
	if(auto* const v = json.find("cells"))
		fromJson(std::move(*v), value.cells);
}

void fromJson(json::Value&& json, NotebookDocumentChangeEvent& value)
{
	auto& obj = json.object();
	notebookDocumentChangeEventFromJson(obj, value);
}

static void didChangeNotebookDocumentParamsFromJson(json::Object& json, DidChangeNotebookDocumentParams& value)
{
	fromJson(std::move(json.get("notebookDocument")), value.notebookDocument);
	fromJson(std::move(json.get("change")), value.change);
}

void fromJson(json::Value&& json, DidChangeNotebookDocumentParams& value)
{
	auto& obj = json.object();
	didChangeNotebookDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeNotebookDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"notebookDocument",
		"change",
		nullptr
	};
	return properties;
}

static void notebookDocumentIdentifierFromJson(json::Object& json, NotebookDocumentIdentifier& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, NotebookDocumentIdentifier& value)
{
	auto& obj = json.object();
	notebookDocumentIdentifierFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentIdentifier>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void didSaveNotebookDocumentParamsFromJson(json::Object& json, DidSaveNotebookDocumentParams& value)
{
	fromJson(std::move(json.get("notebookDocument")), value.notebookDocument);
}

void fromJson(json::Value&& json, DidSaveNotebookDocumentParams& value)
{
	auto& obj = json.object();
	didSaveNotebookDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidSaveNotebookDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"notebookDocument",
		nullptr
	};
	return properties;
}

static void didCloseNotebookDocumentParamsFromJson(json::Object& json, DidCloseNotebookDocumentParams& value)
{
	fromJson(std::move(json.get("notebookDocument")), value.notebookDocument);
	fromJson(std::move(json.get("cellTextDocuments")), value.cellTextDocuments);
}

void fromJson(json::Value&& json, DidCloseNotebookDocumentParams& value)
{
	auto& obj = json.object();
	didCloseNotebookDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidCloseNotebookDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"notebookDocument",
		"cellTextDocuments",
		nullptr
	};
	return properties;
}

static void selectedCompletionInfoFromJson(json::Object& json, SelectedCompletionInfo& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("text")), value.text);
}

void fromJson(json::Value&& json, SelectedCompletionInfo& value)
{
	auto& obj = json.object();
	selectedCompletionInfoFromJson(obj, value);
}

template<>
auto requiredProperties<SelectedCompletionInfo>() -> const char**
{
	static const char* properties[] = {
		"range",
		"text",
		nullptr
	};
	return properties;
}

static void inlineCompletionContextFromJson(json::Object& json, InlineCompletionContext& value)
{
	fromJson(std::move(json.get("triggerKind")), value.triggerKind);
	if(auto* const v = json.find("selectedCompletionInfo"))
		fromJson(std::move(*v), value.selectedCompletionInfo);
}

void fromJson(json::Value&& json, InlineCompletionContext& value)
{
	auto& obj = json.object();
	inlineCompletionContextFromJson(obj, value);
}

template<>
auto requiredProperties<InlineCompletionContext>() -> const char**
{
	static const char* properties[] = {
		"triggerKind",
		nullptr
	};
	return properties;
}

static void inlineCompletionParamsFromJson(json::Object& json, InlineCompletionParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("context")), value.context);
}

void fromJson(json::Value&& json, InlineCompletionParams& value)
{
	auto& obj = json.object();
	inlineCompletionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<InlineCompletionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		"context",
		nullptr
	};
	return properties;
}

static void inlineCompletionItemFromJson(json::Object& json, InlineCompletionItem& value)
{
	fromJson(std::move(json.get("insertText")), value.insertText);
	if(auto* const v = json.find("filterText"))
		fromJson(std::move(*v), value.filterText);
	if(auto* const v = json.find("range"))
		fromJson(std::move(*v), value.range);
	if(auto* const v = json.find("command"))
		fromJson(std::move(*v), value.command);
}

void fromJson(json::Value&& json, InlineCompletionItem& value)
{
	auto& obj = json.object();
	inlineCompletionItemFromJson(obj, value);
}

template<>
auto requiredProperties<InlineCompletionItem>() -> const char**
{
	static const char* properties[] = {
		"insertText",
		nullptr
	};
	return properties;
}

static void inlineCompletionListFromJson(json::Object& json, InlineCompletionList& value)
{
	fromJson(std::move(json.get("items")), value.items);
}

void fromJson(json::Value&& json, InlineCompletionList& value)
{
	auto& obj = json.object();
	inlineCompletionListFromJson(obj, value);
}

template<>
auto requiredProperties<InlineCompletionList>() -> const char**
{
	static const char* properties[] = {
		"items",
		nullptr
	};
	return properties;
}

static void inlineCompletionOptionsFromJson(json::Object& json, InlineCompletionOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, InlineCompletionOptions& value)
{
	auto& obj = json.object();
	inlineCompletionOptionsFromJson(obj, value);
}

static void inlineCompletionRegistrationOptionsFromJson(json::Object& json, InlineCompletionRegistrationOptions& value)
{
	inlineCompletionOptionsFromJson(json, value);
	textDocumentRegistrationOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, InlineCompletionRegistrationOptions& value)
{
	auto& obj = json.object();
	inlineCompletionRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<InlineCompletionRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void textDocumentContentParamsFromJson(json::Object& json, TextDocumentContentParams& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, TextDocumentContentParams& value)
{
	auto& obj = json.object();
	textDocumentContentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentParams>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void textDocumentContentResultFromJson(json::Object& json, TextDocumentContentResult& value)
{
	fromJson(std::move(json.get("text")), value.text);
}

void fromJson(json::Value&& json, TextDocumentContentResult& value)
{
	auto& obj = json.object();
	textDocumentContentResultFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentResult>() -> const char**
{
	static const char* properties[] = {
		"text",
		nullptr
	};
	return properties;
}

static void textDocumentContentOptionsFromJson(json::Object& json, TextDocumentContentOptions& value)
{
	fromJson(std::move(json.get("schemes")), value.schemes);
}

void fromJson(json::Value&& json, TextDocumentContentOptions& value)
{
	auto& obj = json.object();
	textDocumentContentOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentOptions>() -> const char**
{
	static const char* properties[] = {
		"schemes",
		nullptr
	};
	return properties;
}

static void textDocumentContentRegistrationOptionsFromJson(json::Object& json, TextDocumentContentRegistrationOptions& value)
{
	textDocumentContentOptionsFromJson(json, value);
	if(auto* const v = json.find("id"))
		fromJson(std::move(*v), value.id);
}

void fromJson(json::Value&& json, TextDocumentContentRegistrationOptions& value)
{
	auto& obj = json.object();
	textDocumentContentRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"schemes",
		nullptr
	};
	return properties;
}

static void textDocumentContentRefreshParamsFromJson(json::Object& json, TextDocumentContentRefreshParams& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, TextDocumentContentRefreshParams& value)
{
	auto& obj = json.object();
	textDocumentContentRefreshParamsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentContentRefreshParams>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void registrationFromJson(json::Object& json, Registration& value)
{
	fromJson(std::move(json.get("id")), value.id);
	fromJson(std::move(json.get("method")), value.method);
	if(auto* const v = json.find("registerOptions"))
		fromJson(std::move(*v), value.registerOptions);
}

void fromJson(json::Value&& json, Registration& value)
{
	auto& obj = json.object();
	registrationFromJson(obj, value);
}

template<>
auto requiredProperties<Registration>() -> const char**
{
	static const char* properties[] = {
		"id",
		"method",
		nullptr
	};
	return properties;
}

static void registrationParamsFromJson(json::Object& json, RegistrationParams& value)
{
	fromJson(std::move(json.get("registrations")), value.registrations);
}

void fromJson(json::Value&& json, RegistrationParams& value)
{
	auto& obj = json.object();
	registrationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<RegistrationParams>() -> const char**
{
	static const char* properties[] = {
		"registrations",
		nullptr
	};
	return properties;
}

static void unregistrationFromJson(json::Object& json, Unregistration& value)
{
	fromJson(std::move(json.get("id")), value.id);
	fromJson(std::move(json.get("method")), value.method);
}

void fromJson(json::Value&& json, Unregistration& value)
{
	auto& obj = json.object();
	unregistrationFromJson(obj, value);
}

template<>
auto requiredProperties<Unregistration>() -> const char**
{
	static const char* properties[] = {
		"id",
		"method",
		nullptr
	};
	return properties;
}

static void unregistrationParamsFromJson(json::Object& json, UnregistrationParams& value)
{
	fromJson(std::move(json.get("unregisterations")), value.unregisterations);
}

void fromJson(json::Value&& json, UnregistrationParams& value)
{
	auto& obj = json.object();
	unregistrationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<UnregistrationParams>() -> const char**
{
	static const char* properties[] = {
		"unregisterations",
		nullptr
	};
	return properties;
}

static void changeAnnotationsSupportOptionsFromJson(json::Object& json, ChangeAnnotationsSupportOptions& value)
{
	if(auto* const v = json.find("groupsOnLabel"))
		fromJson(std::move(*v), value.groupsOnLabel);
}

void fromJson(json::Value&& json, ChangeAnnotationsSupportOptions& value)
{
	auto& obj = json.object();
	changeAnnotationsSupportOptionsFromJson(obj, value);
}

static void workspaceEditClientCapabilitiesFromJson(json::Object& json, WorkspaceEditClientCapabilities& value)
{
	if(auto* const v = json.find("documentChanges"))
		fromJson(std::move(*v), value.documentChanges);
	if(auto* const v = json.find("resourceOperations"))
		fromJson(std::move(*v), value.resourceOperations);
	if(auto* const v = json.find("failureHandling"))
		fromJson(std::move(*v), value.failureHandling);
	if(auto* const v = json.find("normalizesLineEndings"))
		fromJson(std::move(*v), value.normalizesLineEndings);
	if(auto* const v = json.find("changeAnnotationSupport"))
		fromJson(std::move(*v), value.changeAnnotationSupport);
	if(auto* const v = json.find("metadataSupport"))
		fromJson(std::move(*v), value.metadataSupport);
	if(auto* const v = json.find("snippetEditSupport"))
		fromJson(std::move(*v), value.snippetEditSupport);
}

void fromJson(json::Value&& json, WorkspaceEditClientCapabilities& value)
{
	auto& obj = json.object();
	workspaceEditClientCapabilitiesFromJson(obj, value);
}

static void didChangeConfigurationClientCapabilitiesFromJson(json::Object& json, DidChangeConfigurationClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, DidChangeConfigurationClientCapabilities& value)
{
	auto& obj = json.object();
	didChangeConfigurationClientCapabilitiesFromJson(obj, value);
}

static void didChangeWatchedFilesClientCapabilitiesFromJson(json::Object& json, DidChangeWatchedFilesClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("relativePatternSupport"))
		fromJson(std::move(*v), value.relativePatternSupport);
}

void fromJson(json::Value&& json, DidChangeWatchedFilesClientCapabilities& value)
{
	auto& obj = json.object();
	didChangeWatchedFilesClientCapabilitiesFromJson(obj, value);
}

static void clientSymbolKindOptionsFromJson(json::Object& json, ClientSymbolKindOptions& value)
{
	if(auto* const v = json.find("valueSet"))
		fromJson(std::move(*v), value.valueSet);
}

void fromJson(json::Value&& json, ClientSymbolKindOptions& value)
{
	auto& obj = json.object();
	clientSymbolKindOptionsFromJson(obj, value);
}

static void clientSymbolTagOptionsFromJson(json::Object& json, ClientSymbolTagOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, ClientSymbolTagOptions& value)
{
	auto& obj = json.object();
	clientSymbolTagOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientSymbolTagOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void clientSymbolResolveOptionsFromJson(json::Object& json, ClientSymbolResolveOptions& value)
{
	fromJson(std::move(json.get("properties")), value.properties);
}

void fromJson(json::Value&& json, ClientSymbolResolveOptions& value)
{
	auto& obj = json.object();
	clientSymbolResolveOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientSymbolResolveOptions>() -> const char**
{
	static const char* properties[] = {
		"properties",
		nullptr
	};
	return properties;
}

static void workspaceSymbolClientCapabilitiesFromJson(json::Object& json, WorkspaceSymbolClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("symbolKind"))
		fromJson(std::move(*v), value.symbolKind);
	if(auto* const v = json.find("tagSupport"))
		fromJson(std::move(*v), value.tagSupport);
	if(auto* const v = json.find("resolveSupport"))
		fromJson(std::move(*v), value.resolveSupport);
}

void fromJson(json::Value&& json, WorkspaceSymbolClientCapabilities& value)
{
	auto& obj = json.object();
	workspaceSymbolClientCapabilitiesFromJson(obj, value);
}

static void executeCommandClientCapabilitiesFromJson(json::Object& json, ExecuteCommandClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, ExecuteCommandClientCapabilities& value)
{
	auto& obj = json.object();
	executeCommandClientCapabilitiesFromJson(obj, value);
}

static void semanticTokensWorkspaceClientCapabilitiesFromJson(json::Object& json, SemanticTokensWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, SemanticTokensWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	semanticTokensWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void codeLensWorkspaceClientCapabilitiesFromJson(json::Object& json, CodeLensWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, CodeLensWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	codeLensWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void fileOperationClientCapabilitiesFromJson(json::Object& json, FileOperationClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("didCreate"))
		fromJson(std::move(*v), value.didCreate);
	if(auto* const v = json.find("willCreate"))
		fromJson(std::move(*v), value.willCreate);
	if(auto* const v = json.find("didRename"))
		fromJson(std::move(*v), value.didRename);
	if(auto* const v = json.find("willRename"))
		fromJson(std::move(*v), value.willRename);
	if(auto* const v = json.find("didDelete"))
		fromJson(std::move(*v), value.didDelete);
	if(auto* const v = json.find("willDelete"))
		fromJson(std::move(*v), value.willDelete);
}

void fromJson(json::Value&& json, FileOperationClientCapabilities& value)
{
	auto& obj = json.object();
	fileOperationClientCapabilitiesFromJson(obj, value);
}

static void inlineValueWorkspaceClientCapabilitiesFromJson(json::Object& json, InlineValueWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, InlineValueWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	inlineValueWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void inlayHintWorkspaceClientCapabilitiesFromJson(json::Object& json, InlayHintWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, InlayHintWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	inlayHintWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void diagnosticWorkspaceClientCapabilitiesFromJson(json::Object& json, DiagnosticWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, DiagnosticWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	diagnosticWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void foldingRangeWorkspaceClientCapabilitiesFromJson(json::Object& json, FoldingRangeWorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("refreshSupport"))
		fromJson(std::move(*v), value.refreshSupport);
}

void fromJson(json::Value&& json, FoldingRangeWorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	foldingRangeWorkspaceClientCapabilitiesFromJson(obj, value);
}

static void textDocumentContentClientCapabilitiesFromJson(json::Object& json, TextDocumentContentClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, TextDocumentContentClientCapabilities& value)
{
	auto& obj = json.object();
	textDocumentContentClientCapabilitiesFromJson(obj, value);
}

static void workspaceClientCapabilitiesFromJson(json::Object& json, WorkspaceClientCapabilities& value)
{
	if(auto* const v = json.find("applyEdit"))
		fromJson(std::move(*v), value.applyEdit);
	if(auto* const v = json.find("workspaceEdit"))
		fromJson(std::move(*v), value.workspaceEdit);
	if(auto* const v = json.find("didChangeConfiguration"))
		fromJson(std::move(*v), value.didChangeConfiguration);
	if(auto* const v = json.find("didChangeWatchedFiles"))
		fromJson(std::move(*v), value.didChangeWatchedFiles);
	if(auto* const v = json.find("symbol"))
		fromJson(std::move(*v), value.symbol);
	if(auto* const v = json.find("executeCommand"))
		fromJson(std::move(*v), value.executeCommand);
	if(auto* const v = json.find("workspaceFolders"))
		fromJson(std::move(*v), value.workspaceFolders);
	if(auto* const v = json.find("configuration"))
		fromJson(std::move(*v), value.configuration);
	if(auto* const v = json.find("semanticTokens"))
		fromJson(std::move(*v), value.semanticTokens);
	if(auto* const v = json.find("codeLens"))
		fromJson(std::move(*v), value.codeLens);
	if(auto* const v = json.find("fileOperations"))
		fromJson(std::move(*v), value.fileOperations);
	if(auto* const v = json.find("inlineValue"))
		fromJson(std::move(*v), value.inlineValue);
	if(auto* const v = json.find("inlayHint"))
		fromJson(std::move(*v), value.inlayHint);
	if(auto* const v = json.find("diagnostics"))
		fromJson(std::move(*v), value.diagnostics);
	if(auto* const v = json.find("foldingRange"))
		fromJson(std::move(*v), value.foldingRange);
	if(auto* const v = json.find("textDocumentContent"))
		fromJson(std::move(*v), value.textDocumentContent);
}

void fromJson(json::Value&& json, WorkspaceClientCapabilities& value)
{
	auto& obj = json.object();
	workspaceClientCapabilitiesFromJson(obj, value);
}

static void textDocumentSyncClientCapabilitiesFromJson(json::Object& json, TextDocumentSyncClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("willSave"))
		fromJson(std::move(*v), value.willSave);
	if(auto* const v = json.find("willSaveWaitUntil"))
		fromJson(std::move(*v), value.willSaveWaitUntil);
	if(auto* const v = json.find("didSave"))
		fromJson(std::move(*v), value.didSave);
}

void fromJson(json::Value&& json, TextDocumentSyncClientCapabilities& value)
{
	auto& obj = json.object();
	textDocumentSyncClientCapabilitiesFromJson(obj, value);
}

static void textDocumentFilterClientCapabilitiesFromJson(json::Object& json, TextDocumentFilterClientCapabilities& value)
{
	if(auto* const v = json.find("relativePatternSupport"))
		fromJson(std::move(*v), value.relativePatternSupport);
}

void fromJson(json::Value&& json, TextDocumentFilterClientCapabilities& value)
{
	auto& obj = json.object();
	textDocumentFilterClientCapabilitiesFromJson(obj, value);
}

static void completionItemTagOptionsFromJson(json::Object& json, CompletionItemTagOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, CompletionItemTagOptions& value)
{
	auto& obj = json.object();
	completionItemTagOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionItemTagOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void clientCompletionItemResolveOptionsFromJson(json::Object& json, ClientCompletionItemResolveOptions& value)
{
	fromJson(std::move(json.get("properties")), value.properties);
}

void fromJson(json::Value&& json, ClientCompletionItemResolveOptions& value)
{
	auto& obj = json.object();
	clientCompletionItemResolveOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCompletionItemResolveOptions>() -> const char**
{
	static const char* properties[] = {
		"properties",
		nullptr
	};
	return properties;
}

static void clientCompletionItemInsertTextModeOptionsFromJson(json::Object& json, ClientCompletionItemInsertTextModeOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, ClientCompletionItemInsertTextModeOptions& value)
{
	auto& obj = json.object();
	clientCompletionItemInsertTextModeOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCompletionItemInsertTextModeOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void clientCompletionItemOptionsFromJson(json::Object& json, ClientCompletionItemOptions& value)
{
	if(auto* const v = json.find("snippetSupport"))
		fromJson(std::move(*v), value.snippetSupport);
	if(auto* const v = json.find("commitCharactersSupport"))
		fromJson(std::move(*v), value.commitCharactersSupport);
	if(auto* const v = json.find("documentationFormat"))
		fromJson(std::move(*v), value.documentationFormat);
	if(auto* const v = json.find("deprecatedSupport"))
		fromJson(std::move(*v), value.deprecatedSupport);
	if(auto* const v = json.find("preselectSupport"))
		fromJson(std::move(*v), value.preselectSupport);
	if(auto* const v = json.find("tagSupport"))
		fromJson(std::move(*v), value.tagSupport);
	if(auto* const v = json.find("insertReplaceSupport"))
		fromJson(std::move(*v), value.insertReplaceSupport);
	if(auto* const v = json.find("resolveSupport"))
		fromJson(std::move(*v), value.resolveSupport);
	if(auto* const v = json.find("insertTextModeSupport"))
		fromJson(std::move(*v), value.insertTextModeSupport);
	if(auto* const v = json.find("labelDetailsSupport"))
		fromJson(std::move(*v), value.labelDetailsSupport);
}

void fromJson(json::Value&& json, ClientCompletionItemOptions& value)
{
	auto& obj = json.object();
	clientCompletionItemOptionsFromJson(obj, value);
}

static void clientCompletionItemOptionsKindFromJson(json::Object& json, ClientCompletionItemOptionsKind& value)
{
	if(auto* const v = json.find("valueSet"))
		fromJson(std::move(*v), value.valueSet);
}

void fromJson(json::Value&& json, ClientCompletionItemOptionsKind& value)
{
	auto& obj = json.object();
	clientCompletionItemOptionsKindFromJson(obj, value);
}

static void completionListCapabilitiesFromJson(json::Object& json, CompletionListCapabilities& value)
{
	if(auto* const v = json.find("itemDefaults"))
		fromJson(std::move(*v), value.itemDefaults);
	if(auto* const v = json.find("applyKindSupport"))
		fromJson(std::move(*v), value.applyKindSupport);
}

void fromJson(json::Value&& json, CompletionListCapabilities& value)
{
	auto& obj = json.object();
	completionListCapabilitiesFromJson(obj, value);
}

static void completionClientCapabilitiesFromJson(json::Object& json, CompletionClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("completionItem"))
		fromJson(std::move(*v), value.completionItem);
	if(auto* const v = json.find("completionItemKind"))
		fromJson(std::move(*v), value.completionItemKind);
	if(auto* const v = json.find("insertTextMode"))
		fromJson(std::move(*v), value.insertTextMode);
	if(auto* const v = json.find("contextSupport"))
		fromJson(std::move(*v), value.contextSupport);
	if(auto* const v = json.find("completionList"))
		fromJson(std::move(*v), value.completionList);
}

void fromJson(json::Value&& json, CompletionClientCapabilities& value)
{
	auto& obj = json.object();
	completionClientCapabilitiesFromJson(obj, value);
}

static void hoverClientCapabilitiesFromJson(json::Object& json, HoverClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("contentFormat"))
		fromJson(std::move(*v), value.contentFormat);
}

void fromJson(json::Value&& json, HoverClientCapabilities& value)
{
	auto& obj = json.object();
	hoverClientCapabilitiesFromJson(obj, value);
}

static void clientSignatureParameterInformationOptionsFromJson(json::Object& json, ClientSignatureParameterInformationOptions& value)
{
	if(auto* const v = json.find("labelOffsetSupport"))
		fromJson(std::move(*v), value.labelOffsetSupport);
}

void fromJson(json::Value&& json, ClientSignatureParameterInformationOptions& value)
{
	auto& obj = json.object();
	clientSignatureParameterInformationOptionsFromJson(obj, value);
}

static void clientSignatureInformationOptionsFromJson(json::Object& json, ClientSignatureInformationOptions& value)
{
	if(auto* const v = json.find("documentationFormat"))
		fromJson(std::move(*v), value.documentationFormat);
	if(auto* const v = json.find("parameterInformation"))
		fromJson(std::move(*v), value.parameterInformation);
	if(auto* const v = json.find("activeParameterSupport"))
		fromJson(std::move(*v), value.activeParameterSupport);
	if(auto* const v = json.find("noActiveParameterSupport"))
		fromJson(std::move(*v), value.noActiveParameterSupport);
}

void fromJson(json::Value&& json, ClientSignatureInformationOptions& value)
{
	auto& obj = json.object();
	clientSignatureInformationOptionsFromJson(obj, value);
}

static void signatureHelpClientCapabilitiesFromJson(json::Object& json, SignatureHelpClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("signatureInformation"))
		fromJson(std::move(*v), value.signatureInformation);
	if(auto* const v = json.find("contextSupport"))
		fromJson(std::move(*v), value.contextSupport);
}

void fromJson(json::Value&& json, SignatureHelpClientCapabilities& value)
{
	auto& obj = json.object();
	signatureHelpClientCapabilitiesFromJson(obj, value);
}

static void declarationClientCapabilitiesFromJson(json::Object& json, DeclarationClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("linkSupport"))
		fromJson(std::move(*v), value.linkSupport);
}

void fromJson(json::Value&& json, DeclarationClientCapabilities& value)
{
	auto& obj = json.object();
	declarationClientCapabilitiesFromJson(obj, value);
}

static void definitionClientCapabilitiesFromJson(json::Object& json, DefinitionClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("linkSupport"))
		fromJson(std::move(*v), value.linkSupport);
}

void fromJson(json::Value&& json, DefinitionClientCapabilities& value)
{
	auto& obj = json.object();
	definitionClientCapabilitiesFromJson(obj, value);
}

static void typeDefinitionClientCapabilitiesFromJson(json::Object& json, TypeDefinitionClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("linkSupport"))
		fromJson(std::move(*v), value.linkSupport);
}

void fromJson(json::Value&& json, TypeDefinitionClientCapabilities& value)
{
	auto& obj = json.object();
	typeDefinitionClientCapabilitiesFromJson(obj, value);
}

static void implementationClientCapabilitiesFromJson(json::Object& json, ImplementationClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("linkSupport"))
		fromJson(std::move(*v), value.linkSupport);
}

void fromJson(json::Value&& json, ImplementationClientCapabilities& value)
{
	auto& obj = json.object();
	implementationClientCapabilitiesFromJson(obj, value);
}

static void referenceClientCapabilitiesFromJson(json::Object& json, ReferenceClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, ReferenceClientCapabilities& value)
{
	auto& obj = json.object();
	referenceClientCapabilitiesFromJson(obj, value);
}

static void documentHighlightClientCapabilitiesFromJson(json::Object& json, DocumentHighlightClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, DocumentHighlightClientCapabilities& value)
{
	auto& obj = json.object();
	documentHighlightClientCapabilitiesFromJson(obj, value);
}

static void documentSymbolClientCapabilitiesFromJson(json::Object& json, DocumentSymbolClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("symbolKind"))
		fromJson(std::move(*v), value.symbolKind);
	if(auto* const v = json.find("hierarchicalDocumentSymbolSupport"))
		fromJson(std::move(*v), value.hierarchicalDocumentSymbolSupport);
	if(auto* const v = json.find("tagSupport"))
		fromJson(std::move(*v), value.tagSupport);
	if(auto* const v = json.find("labelSupport"))
		fromJson(std::move(*v), value.labelSupport);
}

void fromJson(json::Value&& json, DocumentSymbolClientCapabilities& value)
{
	auto& obj = json.object();
	documentSymbolClientCapabilitiesFromJson(obj, value);
}

static void clientCodeActionKindOptionsFromJson(json::Object& json, ClientCodeActionKindOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, ClientCodeActionKindOptions& value)
{
	auto& obj = json.object();
	clientCodeActionKindOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCodeActionKindOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void clientCodeActionLiteralOptionsFromJson(json::Object& json, ClientCodeActionLiteralOptions& value)
{
	fromJson(std::move(json.get("codeActionKind")), value.codeActionKind);
}

void fromJson(json::Value&& json, ClientCodeActionLiteralOptions& value)
{
	auto& obj = json.object();
	clientCodeActionLiteralOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCodeActionLiteralOptions>() -> const char**
{
	static const char* properties[] = {
		"codeActionKind",
		nullptr
	};
	return properties;
}

static void clientCodeActionResolveOptionsFromJson(json::Object& json, ClientCodeActionResolveOptions& value)
{
	fromJson(std::move(json.get("properties")), value.properties);
}

void fromJson(json::Value&& json, ClientCodeActionResolveOptions& value)
{
	auto& obj = json.object();
	clientCodeActionResolveOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCodeActionResolveOptions>() -> const char**
{
	static const char* properties[] = {
		"properties",
		nullptr
	};
	return properties;
}

static void codeActionTagOptionsFromJson(json::Object& json, CodeActionTagOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, CodeActionTagOptions& value)
{
	auto& obj = json.object();
	codeActionTagOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionTagOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void codeActionClientCapabilitiesFromJson(json::Object& json, CodeActionClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("codeActionLiteralSupport"))
		fromJson(std::move(*v), value.codeActionLiteralSupport);
	if(auto* const v = json.find("isPreferredSupport"))
		fromJson(std::move(*v), value.isPreferredSupport);
	if(auto* const v = json.find("disabledSupport"))
		fromJson(std::move(*v), value.disabledSupport);
	if(auto* const v = json.find("dataSupport"))
		fromJson(std::move(*v), value.dataSupport);
	if(auto* const v = json.find("resolveSupport"))
		fromJson(std::move(*v), value.resolveSupport);
	if(auto* const v = json.find("honorsChangeAnnotations"))
		fromJson(std::move(*v), value.honorsChangeAnnotations);
	if(auto* const v = json.find("documentationSupport"))
		fromJson(std::move(*v), value.documentationSupport);
	if(auto* const v = json.find("tagSupport"))
		fromJson(std::move(*v), value.tagSupport);
}

void fromJson(json::Value&& json, CodeActionClientCapabilities& value)
{
	auto& obj = json.object();
	codeActionClientCapabilitiesFromJson(obj, value);
}

static void clientCodeLensResolveOptionsFromJson(json::Object& json, ClientCodeLensResolveOptions& value)
{
	fromJson(std::move(json.get("properties")), value.properties);
}

void fromJson(json::Value&& json, ClientCodeLensResolveOptions& value)
{
	auto& obj = json.object();
	clientCodeLensResolveOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientCodeLensResolveOptions>() -> const char**
{
	static const char* properties[] = {
		"properties",
		nullptr
	};
	return properties;
}

static void codeLensClientCapabilitiesFromJson(json::Object& json, CodeLensClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("resolveSupport"))
		fromJson(std::move(*v), value.resolveSupport);
}

void fromJson(json::Value&& json, CodeLensClientCapabilities& value)
{
	auto& obj = json.object();
	codeLensClientCapabilitiesFromJson(obj, value);
}

static void documentLinkClientCapabilitiesFromJson(json::Object& json, DocumentLinkClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("tooltipSupport"))
		fromJson(std::move(*v), value.tooltipSupport);
}

void fromJson(json::Value&& json, DocumentLinkClientCapabilities& value)
{
	auto& obj = json.object();
	documentLinkClientCapabilitiesFromJson(obj, value);
}

static void documentColorClientCapabilitiesFromJson(json::Object& json, DocumentColorClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, DocumentColorClientCapabilities& value)
{
	auto& obj = json.object();
	documentColorClientCapabilitiesFromJson(obj, value);
}

static void documentFormattingClientCapabilitiesFromJson(json::Object& json, DocumentFormattingClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, DocumentFormattingClientCapabilities& value)
{
	auto& obj = json.object();
	documentFormattingClientCapabilitiesFromJson(obj, value);
}

static void documentRangeFormattingClientCapabilitiesFromJson(json::Object& json, DocumentRangeFormattingClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("rangesSupport"))
		fromJson(std::move(*v), value.rangesSupport);
}

void fromJson(json::Value&& json, DocumentRangeFormattingClientCapabilities& value)
{
	auto& obj = json.object();
	documentRangeFormattingClientCapabilitiesFromJson(obj, value);
}

static void documentOnTypeFormattingClientCapabilitiesFromJson(json::Object& json, DocumentOnTypeFormattingClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, DocumentOnTypeFormattingClientCapabilities& value)
{
	auto& obj = json.object();
	documentOnTypeFormattingClientCapabilitiesFromJson(obj, value);
}

static void renameClientCapabilitiesFromJson(json::Object& json, RenameClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("prepareSupport"))
		fromJson(std::move(*v), value.prepareSupport);
	if(auto* const v = json.find("prepareSupportDefaultBehavior"))
		fromJson(std::move(*v), value.prepareSupportDefaultBehavior);
	if(auto* const v = json.find("honorsChangeAnnotations"))
		fromJson(std::move(*v), value.honorsChangeAnnotations);
}

void fromJson(json::Value&& json, RenameClientCapabilities& value)
{
	auto& obj = json.object();
	renameClientCapabilitiesFromJson(obj, value);
}

static void clientFoldingRangeKindOptionsFromJson(json::Object& json, ClientFoldingRangeKindOptions& value)
{
	if(auto* const v = json.find("valueSet"))
		fromJson(std::move(*v), value.valueSet);
}

void fromJson(json::Value&& json, ClientFoldingRangeKindOptions& value)
{
	auto& obj = json.object();
	clientFoldingRangeKindOptionsFromJson(obj, value);
}

static void clientFoldingRangeOptionsFromJson(json::Object& json, ClientFoldingRangeOptions& value)
{
	if(auto* const v = json.find("collapsedText"))
		fromJson(std::move(*v), value.collapsedText);
}

void fromJson(json::Value&& json, ClientFoldingRangeOptions& value)
{
	auto& obj = json.object();
	clientFoldingRangeOptionsFromJson(obj, value);
}

static void foldingRangeClientCapabilitiesFromJson(json::Object& json, FoldingRangeClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("rangeLimit"))
		fromJson(std::move(*v), value.rangeLimit);
	if(auto* const v = json.find("lineFoldingOnly"))
		fromJson(std::move(*v), value.lineFoldingOnly);
	if(auto* const v = json.find("foldingRangeKind"))
		fromJson(std::move(*v), value.foldingRangeKind);
	if(auto* const v = json.find("foldingRange"))
		fromJson(std::move(*v), value.foldingRange);
}

void fromJson(json::Value&& json, FoldingRangeClientCapabilities& value)
{
	auto& obj = json.object();
	foldingRangeClientCapabilitiesFromJson(obj, value);
}

static void selectionRangeClientCapabilitiesFromJson(json::Object& json, SelectionRangeClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, SelectionRangeClientCapabilities& value)
{
	auto& obj = json.object();
	selectionRangeClientCapabilitiesFromJson(obj, value);
}

static void clientDiagnosticsTagOptionsFromJson(json::Object& json, ClientDiagnosticsTagOptions& value)
{
	fromJson(std::move(json.get("valueSet")), value.valueSet);
}

void fromJson(json::Value&& json, ClientDiagnosticsTagOptions& value)
{
	auto& obj = json.object();
	clientDiagnosticsTagOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientDiagnosticsTagOptions>() -> const char**
{
	static const char* properties[] = {
		"valueSet",
		nullptr
	};
	return properties;
}

static void diagnosticsCapabilitiesFromJson(json::Object& json, DiagnosticsCapabilities& value)
{
	if(auto* const v = json.find("relatedInformation"))
		fromJson(std::move(*v), value.relatedInformation);
	if(auto* const v = json.find("tagSupport"))
		fromJson(std::move(*v), value.tagSupport);
	if(auto* const v = json.find("codeDescriptionSupport"))
		fromJson(std::move(*v), value.codeDescriptionSupport);
	if(auto* const v = json.find("dataSupport"))
		fromJson(std::move(*v), value.dataSupport);
}

void fromJson(json::Value&& json, DiagnosticsCapabilities& value)
{
	auto& obj = json.object();
	diagnosticsCapabilitiesFromJson(obj, value);
}

static void publishDiagnosticsClientCapabilitiesFromJson(json::Object& json, PublishDiagnosticsClientCapabilities& value)
{
	diagnosticsCapabilitiesFromJson(json, value);
	if(auto* const v = json.find("versionSupport"))
		fromJson(std::move(*v), value.versionSupport);
}

void fromJson(json::Value&& json, PublishDiagnosticsClientCapabilities& value)
{
	auto& obj = json.object();
	publishDiagnosticsClientCapabilitiesFromJson(obj, value);
}

static void callHierarchyClientCapabilitiesFromJson(json::Object& json, CallHierarchyClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, CallHierarchyClientCapabilities& value)
{
	auto& obj = json.object();
	callHierarchyClientCapabilitiesFromJson(obj, value);
}

static void clientSemanticTokensRequestOptionsRangeFromJson(json::Object& json, ClientSemanticTokensRequestOptionsRange& value)
{
}

void fromJson(json::Value&& json, ClientSemanticTokensRequestOptionsRange& value)
{
	auto& obj = json.object();
	clientSemanticTokensRequestOptionsRangeFromJson(obj, value);
}

static void clientSemanticTokensRequestFullDeltaFromJson(json::Object& json, ClientSemanticTokensRequestFullDelta& value)
{
	if(auto* const v = json.find("delta"))
		fromJson(std::move(*v), value.delta);
}

void fromJson(json::Value&& json, ClientSemanticTokensRequestFullDelta& value)
{
	auto& obj = json.object();
	clientSemanticTokensRequestFullDeltaFromJson(obj, value);
}

static void clientSemanticTokensRequestOptionsFromJson(json::Object& json, ClientSemanticTokensRequestOptions& value)
{
	if(auto* const v = json.find("range"))
		fromJson(std::move(*v), value.range);
	if(auto* const v = json.find("full"))
		fromJson(std::move(*v), value.full);
}

void fromJson(json::Value&& json, ClientSemanticTokensRequestOptions& value)
{
	auto& obj = json.object();
	clientSemanticTokensRequestOptionsFromJson(obj, value);
}

static void semanticTokensClientCapabilitiesFromJson(json::Object& json, SemanticTokensClientCapabilities& value)
{
	fromJson(std::move(json.get("requests")), value.requests);
	fromJson(std::move(json.get("tokenTypes")), value.tokenTypes);
	fromJson(std::move(json.get("tokenModifiers")), value.tokenModifiers);
	fromJson(std::move(json.get("formats")), value.formats);
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("overlappingTokenSupport"))
		fromJson(std::move(*v), value.overlappingTokenSupport);
	if(auto* const v = json.find("multilineTokenSupport"))
		fromJson(std::move(*v), value.multilineTokenSupport);
	if(auto* const v = json.find("serverCancelSupport"))
		fromJson(std::move(*v), value.serverCancelSupport);
	if(auto* const v = json.find("augmentsSyntaxTokens"))
		fromJson(std::move(*v), value.augmentsSyntaxTokens);
}

void fromJson(json::Value&& json, SemanticTokensClientCapabilities& value)
{
	auto& obj = json.object();
	semanticTokensClientCapabilitiesFromJson(obj, value);
}

template<>
auto requiredProperties<SemanticTokensClientCapabilities>() -> const char**
{
	static const char* properties[] = {
		"requests",
		"tokenTypes",
		"tokenModifiers",
		"formats",
		nullptr
	};
	return properties;
}

static void linkedEditingRangeClientCapabilitiesFromJson(json::Object& json, LinkedEditingRangeClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, LinkedEditingRangeClientCapabilities& value)
{
	auto& obj = json.object();
	linkedEditingRangeClientCapabilitiesFromJson(obj, value);
}

static void monikerClientCapabilitiesFromJson(json::Object& json, MonikerClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, MonikerClientCapabilities& value)
{
	auto& obj = json.object();
	monikerClientCapabilitiesFromJson(obj, value);
}

static void typeHierarchyClientCapabilitiesFromJson(json::Object& json, TypeHierarchyClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, TypeHierarchyClientCapabilities& value)
{
	auto& obj = json.object();
	typeHierarchyClientCapabilitiesFromJson(obj, value);
}

static void inlineValueClientCapabilitiesFromJson(json::Object& json, InlineValueClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, InlineValueClientCapabilities& value)
{
	auto& obj = json.object();
	inlineValueClientCapabilitiesFromJson(obj, value);
}

static void clientInlayHintResolveOptionsFromJson(json::Object& json, ClientInlayHintResolveOptions& value)
{
	fromJson(std::move(json.get("properties")), value.properties);
}

void fromJson(json::Value&& json, ClientInlayHintResolveOptions& value)
{
	auto& obj = json.object();
	clientInlayHintResolveOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ClientInlayHintResolveOptions>() -> const char**
{
	static const char* properties[] = {
		"properties",
		nullptr
	};
	return properties;
}

static void inlayHintClientCapabilitiesFromJson(json::Object& json, InlayHintClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("resolveSupport"))
		fromJson(std::move(*v), value.resolveSupport);
}

void fromJson(json::Value&& json, InlayHintClientCapabilities& value)
{
	auto& obj = json.object();
	inlayHintClientCapabilitiesFromJson(obj, value);
}

static void diagnosticClientCapabilitiesFromJson(json::Object& json, DiagnosticClientCapabilities& value)
{
	diagnosticsCapabilitiesFromJson(json, value);
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("relatedDocumentSupport"))
		fromJson(std::move(*v), value.relatedDocumentSupport);
	if(auto* const v = json.find("markupMessageSupport"))
		fromJson(std::move(*v), value.markupMessageSupport);
}

void fromJson(json::Value&& json, DiagnosticClientCapabilities& value)
{
	auto& obj = json.object();
	diagnosticClientCapabilitiesFromJson(obj, value);
}

static void inlineCompletionClientCapabilitiesFromJson(json::Object& json, InlineCompletionClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
}

void fromJson(json::Value&& json, InlineCompletionClientCapabilities& value)
{
	auto& obj = json.object();
	inlineCompletionClientCapabilitiesFromJson(obj, value);
}

static void textDocumentClientCapabilitiesFromJson(json::Object& json, TextDocumentClientCapabilities& value)
{
	if(auto* const v = json.find("synchronization"))
		fromJson(std::move(*v), value.synchronization);
	if(auto* const v = json.find("filters"))
		fromJson(std::move(*v), value.filters);
	if(auto* const v = json.find("completion"))
		fromJson(std::move(*v), value.completion);
	if(auto* const v = json.find("hover"))
		fromJson(std::move(*v), value.hover);
	if(auto* const v = json.find("signatureHelp"))
		fromJson(std::move(*v), value.signatureHelp);
	if(auto* const v = json.find("declaration"))
		fromJson(std::move(*v), value.declaration);
	if(auto* const v = json.find("definition"))
		fromJson(std::move(*v), value.definition);
	if(auto* const v = json.find("typeDefinition"))
		fromJson(std::move(*v), value.typeDefinition);
	if(auto* const v = json.find("implementation"))
		fromJson(std::move(*v), value.implementation);
	if(auto* const v = json.find("references"))
		fromJson(std::move(*v), value.references);
	if(auto* const v = json.find("documentHighlight"))
		fromJson(std::move(*v), value.documentHighlight);
	if(auto* const v = json.find("documentSymbol"))
		fromJson(std::move(*v), value.documentSymbol);
	if(auto* const v = json.find("codeAction"))
		fromJson(std::move(*v), value.codeAction);
	if(auto* const v = json.find("codeLens"))
		fromJson(std::move(*v), value.codeLens);
	if(auto* const v = json.find("documentLink"))
		fromJson(std::move(*v), value.documentLink);
	if(auto* const v = json.find("colorProvider"))
		fromJson(std::move(*v), value.colorProvider);
	if(auto* const v = json.find("formatting"))
		fromJson(std::move(*v), value.formatting);
	if(auto* const v = json.find("rangeFormatting"))
		fromJson(std::move(*v), value.rangeFormatting);
	if(auto* const v = json.find("onTypeFormatting"))
		fromJson(std::move(*v), value.onTypeFormatting);
	if(auto* const v = json.find("rename"))
		fromJson(std::move(*v), value.rename);
	if(auto* const v = json.find("foldingRange"))
		fromJson(std::move(*v), value.foldingRange);
	if(auto* const v = json.find("selectionRange"))
		fromJson(std::move(*v), value.selectionRange);
	if(auto* const v = json.find("publishDiagnostics"))
		fromJson(std::move(*v), value.publishDiagnostics);
	if(auto* const v = json.find("callHierarchy"))
		fromJson(std::move(*v), value.callHierarchy);
	if(auto* const v = json.find("semanticTokens"))
		fromJson(std::move(*v), value.semanticTokens);
	if(auto* const v = json.find("linkedEditingRange"))
		fromJson(std::move(*v), value.linkedEditingRange);
	if(auto* const v = json.find("moniker"))
		fromJson(std::move(*v), value.moniker);
	if(auto* const v = json.find("typeHierarchy"))
		fromJson(std::move(*v), value.typeHierarchy);
	if(auto* const v = json.find("inlineValue"))
		fromJson(std::move(*v), value.inlineValue);
	if(auto* const v = json.find("inlayHint"))
		fromJson(std::move(*v), value.inlayHint);
	if(auto* const v = json.find("diagnostic"))
		fromJson(std::move(*v), value.diagnostic);
	if(auto* const v = json.find("inlineCompletion"))
		fromJson(std::move(*v), value.inlineCompletion);
}

void fromJson(json::Value&& json, TextDocumentClientCapabilities& value)
{
	auto& obj = json.object();
	textDocumentClientCapabilitiesFromJson(obj, value);
}

static void notebookDocumentSyncClientCapabilitiesFromJson(json::Object& json, NotebookDocumentSyncClientCapabilities& value)
{
	if(auto* const v = json.find("dynamicRegistration"))
		fromJson(std::move(*v), value.dynamicRegistration);
	if(auto* const v = json.find("executionSummarySupport"))
		fromJson(std::move(*v), value.executionSummarySupport);
}

void fromJson(json::Value&& json, NotebookDocumentSyncClientCapabilities& value)
{
	auto& obj = json.object();
	notebookDocumentSyncClientCapabilitiesFromJson(obj, value);
}

static void notebookDocumentClientCapabilitiesFromJson(json::Object& json, NotebookDocumentClientCapabilities& value)
{
	fromJson(std::move(json.get("synchronization")), value.synchronization);
}

void fromJson(json::Value&& json, NotebookDocumentClientCapabilities& value)
{
	auto& obj = json.object();
	notebookDocumentClientCapabilitiesFromJson(obj, value);
}

template<>
auto requiredProperties<NotebookDocumentClientCapabilities>() -> const char**
{
	static const char* properties[] = {
		"synchronization",
		nullptr
	};
	return properties;
}

static void clientShowMessageActionItemOptionsFromJson(json::Object& json, ClientShowMessageActionItemOptions& value)
{
	if(auto* const v = json.find("additionalPropertiesSupport"))
		fromJson(std::move(*v), value.additionalPropertiesSupport);
}

void fromJson(json::Value&& json, ClientShowMessageActionItemOptions& value)
{
	auto& obj = json.object();
	clientShowMessageActionItemOptionsFromJson(obj, value);
}

static void showMessageRequestClientCapabilitiesFromJson(json::Object& json, ShowMessageRequestClientCapabilities& value)
{
	if(auto* const v = json.find("messageActionItem"))
		fromJson(std::move(*v), value.messageActionItem);
}

void fromJson(json::Value&& json, ShowMessageRequestClientCapabilities& value)
{
	auto& obj = json.object();
	showMessageRequestClientCapabilitiesFromJson(obj, value);
}

static void showDocumentClientCapabilitiesFromJson(json::Object& json, ShowDocumentClientCapabilities& value)
{
	fromJson(std::move(json.get("support")), value.support);
}

void fromJson(json::Value&& json, ShowDocumentClientCapabilities& value)
{
	auto& obj = json.object();
	showDocumentClientCapabilitiesFromJson(obj, value);
}

template<>
auto requiredProperties<ShowDocumentClientCapabilities>() -> const char**
{
	static const char* properties[] = {
		"support",
		nullptr
	};
	return properties;
}

static void windowClientCapabilitiesFromJson(json::Object& json, WindowClientCapabilities& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("showMessage"))
		fromJson(std::move(*v), value.showMessage);
	if(auto* const v = json.find("showDocument"))
		fromJson(std::move(*v), value.showDocument);
}

void fromJson(json::Value&& json, WindowClientCapabilities& value)
{
	auto& obj = json.object();
	windowClientCapabilitiesFromJson(obj, value);
}

static void staleRequestSupportOptionsFromJson(json::Object& json, StaleRequestSupportOptions& value)
{
	fromJson(std::move(json.get("cancel")), value.cancel);
	fromJson(std::move(json.get("retryOnContentModified")), value.retryOnContentModified);
}

void fromJson(json::Value&& json, StaleRequestSupportOptions& value)
{
	auto& obj = json.object();
	staleRequestSupportOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<StaleRequestSupportOptions>() -> const char**
{
	static const char* properties[] = {
		"cancel",
		"retryOnContentModified",
		nullptr
	};
	return properties;
}

static void regularExpressionsClientCapabilitiesFromJson(json::Object& json, RegularExpressionsClientCapabilities& value)
{
	fromJson(std::move(json.get("engine")), value.engine);
	if(auto* const v = json.find("version"))
		fromJson(std::move(*v), value.version);
}

void fromJson(json::Value&& json, RegularExpressionsClientCapabilities& value)
{
	auto& obj = json.object();
	regularExpressionsClientCapabilitiesFromJson(obj, value);
}

template<>
auto requiredProperties<RegularExpressionsClientCapabilities>() -> const char**
{
	static const char* properties[] = {
		"engine",
		nullptr
	};
	return properties;
}

static void markdownClientCapabilitiesFromJson(json::Object& json, MarkdownClientCapabilities& value)
{
	fromJson(std::move(json.get("parser")), value.parser);
	if(auto* const v = json.find("version"))
		fromJson(std::move(*v), value.version);
	if(auto* const v = json.find("allowedTags"))
		fromJson(std::move(*v), value.allowedTags);
}

void fromJson(json::Value&& json, MarkdownClientCapabilities& value)
{
	auto& obj = json.object();
	markdownClientCapabilitiesFromJson(obj, value);
}

template<>
auto requiredProperties<MarkdownClientCapabilities>() -> const char**
{
	static const char* properties[] = {
		"parser",
		nullptr
	};
	return properties;
}

static void generalClientCapabilitiesFromJson(json::Object& json, GeneralClientCapabilities& value)
{
	if(auto* const v = json.find("staleRequestSupport"))
		fromJson(std::move(*v), value.staleRequestSupport);
	if(auto* const v = json.find("regularExpressions"))
		fromJson(std::move(*v), value.regularExpressions);
	if(auto* const v = json.find("markdown"))
		fromJson(std::move(*v), value.markdown);
	if(auto* const v = json.find("positionEncodings"))
		fromJson(std::move(*v), value.positionEncodings);
}

void fromJson(json::Value&& json, GeneralClientCapabilities& value)
{
	auto& obj = json.object();
	generalClientCapabilitiesFromJson(obj, value);
}

static void clientCapabilitiesFromJson(json::Object& json, ClientCapabilities& value)
{
	if(auto* const v = json.find("workspace"))
		fromJson(std::move(*v), value.workspace);
	if(auto* const v = json.find("textDocument"))
		fromJson(std::move(*v), value.textDocument);
	if(auto* const v = json.find("notebookDocument"))
		fromJson(std::move(*v), value.notebookDocument);
	if(auto* const v = json.find("window"))
		fromJson(std::move(*v), value.window);
	if(auto* const v = json.find("general"))
		fromJson(std::move(*v), value.general);
	if(auto* const v = json.find("experimental"))
		fromJson(std::move(*v), value.experimental);
}

void fromJson(json::Value&& json, ClientCapabilities& value)
{
	auto& obj = json.object();
	clientCapabilitiesFromJson(obj, value);
}

static void clientInfoFromJson(json::Object& json, ClientInfo& value)
{
	fromJson(std::move(json.get("name")), value.name);
	if(auto* const v = json.find("version"))
		fromJson(std::move(*v), value.version);
}

void fromJson(json::Value&& json, ClientInfo& value)
{
	auto& obj = json.object();
	clientInfoFromJson(obj, value);
}

template<>
auto requiredProperties<ClientInfo>() -> const char**
{
	static const char* properties[] = {
		"name",
		nullptr
	};
	return properties;
}

static void _InitializeParamsFromJson(json::Object& json, _InitializeParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("processId")), value.processId);
	fromJson(std::move(json.get("rootUri")), value.rootUri);
	fromJson(std::move(json.get("capabilities")), value.capabilities);
	if(auto* const v = json.find("clientInfo"))
		fromJson(std::move(*v), value.clientInfo);
	if(auto* const v = json.find("locale"))
		fromJson(std::move(*v), value.locale);
	if(auto* const v = json.find("rootPath"))
		fromJson(std::move(*v), value.rootPath);
	if(auto* const v = json.find("initializationOptions"))
		fromJson(std::move(*v), value.initializationOptions);
	if(auto* const v = json.find("trace"))
		fromJson(std::move(*v), value.trace);
}

void fromJson(json::Value&& json, _InitializeParams& value)
{
	auto& obj = json.object();
	_InitializeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<_InitializeParams>() -> const char**
{
	static const char* properties[] = {
		"processId",
		"rootUri",
		"capabilities",
		nullptr
	};
	return properties;
}

static void workspaceFoldersInitializeParamsFromJson(json::Object& json, WorkspaceFoldersInitializeParams& value)
{
	if(auto* const v = json.find("workspaceFolders"))
		fromJson(std::move(*v), value.workspaceFolders);
}

void fromJson(json::Value&& json, WorkspaceFoldersInitializeParams& value)
{
	auto& obj = json.object();
	workspaceFoldersInitializeParamsFromJson(obj, value);
}

static void initializeParamsFromJson(json::Object& json, InitializeParams& value)
{
	_InitializeParamsFromJson(json, value);
	workspaceFoldersInitializeParamsFromJson(json, value);
}

void fromJson(json::Value&& json, InitializeParams& value)
{
	auto& obj = json.object();
	initializeParamsFromJson(obj, value);
}

template<>
auto requiredProperties<InitializeParams>() -> const char**
{
	static const char* properties[] = {
		"processId",
		"rootUri",
		"capabilities",
		nullptr
	};
	return properties;
}

static void saveOptionsFromJson(json::Object& json, SaveOptions& value)
{
	if(auto* const v = json.find("includeText"))
		fromJson(std::move(*v), value.includeText);
}

void fromJson(json::Value&& json, SaveOptions& value)
{
	auto& obj = json.object();
	saveOptionsFromJson(obj, value);
}

static void textDocumentSyncOptionsFromJson(json::Object& json, TextDocumentSyncOptions& value)
{
	if(auto* const v = json.find("openClose"))
		fromJson(std::move(*v), value.openClose);
	if(auto* const v = json.find("change"))
		fromJson(std::move(*v), value.change);
	if(auto* const v = json.find("willSave"))
		fromJson(std::move(*v), value.willSave);
	if(auto* const v = json.find("willSaveWaitUntil"))
		fromJson(std::move(*v), value.willSaveWaitUntil);
	if(auto* const v = json.find("save"))
		fromJson(std::move(*v), value.save);
}

void fromJson(json::Value&& json, TextDocumentSyncOptions& value)
{
	auto& obj = json.object();
	textDocumentSyncOptionsFromJson(obj, value);
}

static void serverCompletionItemOptionsFromJson(json::Object& json, ServerCompletionItemOptions& value)
{
	if(auto* const v = json.find("labelDetailsSupport"))
		fromJson(std::move(*v), value.labelDetailsSupport);
}

void fromJson(json::Value&& json, ServerCompletionItemOptions& value)
{
	auto& obj = json.object();
	serverCompletionItemOptionsFromJson(obj, value);
}

static void completionOptionsFromJson(json::Object& json, CompletionOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("triggerCharacters"))
		fromJson(std::move(*v), value.triggerCharacters);
	if(auto* const v = json.find("allCommitCharacters"))
		fromJson(std::move(*v), value.allCommitCharacters);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
	if(auto* const v = json.find("completionItem"))
		fromJson(std::move(*v), value.completionItem);
}

void fromJson(json::Value&& json, CompletionOptions& value)
{
	auto& obj = json.object();
	completionOptionsFromJson(obj, value);
}

static void hoverOptionsFromJson(json::Object& json, HoverOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, HoverOptions& value)
{
	auto& obj = json.object();
	hoverOptionsFromJson(obj, value);
}

static void signatureHelpOptionsFromJson(json::Object& json, SignatureHelpOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("triggerCharacters"))
		fromJson(std::move(*v), value.triggerCharacters);
	if(auto* const v = json.find("retriggerCharacters"))
		fromJson(std::move(*v), value.retriggerCharacters);
}

void fromJson(json::Value&& json, SignatureHelpOptions& value)
{
	auto& obj = json.object();
	signatureHelpOptionsFromJson(obj, value);
}

static void definitionOptionsFromJson(json::Object& json, DefinitionOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, DefinitionOptions& value)
{
	auto& obj = json.object();
	definitionOptionsFromJson(obj, value);
}

static void referenceOptionsFromJson(json::Object& json, ReferenceOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, ReferenceOptions& value)
{
	auto& obj = json.object();
	referenceOptionsFromJson(obj, value);
}

static void documentHighlightOptionsFromJson(json::Object& json, DocumentHighlightOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, DocumentHighlightOptions& value)
{
	auto& obj = json.object();
	documentHighlightOptionsFromJson(obj, value);
}

static void documentSymbolOptionsFromJson(json::Object& json, DocumentSymbolOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("label"))
		fromJson(std::move(*v), value.label);
}

void fromJson(json::Value&& json, DocumentSymbolOptions& value)
{
	auto& obj = json.object();
	documentSymbolOptionsFromJson(obj, value);
}

static void codeActionKindDocumentationFromJson(json::Object& json, CodeActionKindDocumentation& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("command")), value.command);
}

void fromJson(json::Value&& json, CodeActionKindDocumentation& value)
{
	auto& obj = json.object();
	codeActionKindDocumentationFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionKindDocumentation>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"command",
		nullptr
	};
	return properties;
}

static void codeActionOptionsFromJson(json::Object& json, CodeActionOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("codeActionKinds"))
		fromJson(std::move(*v), value.codeActionKinds);
	if(auto* const v = json.find("documentation"))
		fromJson(std::move(*v), value.documentation);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
}

void fromJson(json::Value&& json, CodeActionOptions& value)
{
	auto& obj = json.object();
	codeActionOptionsFromJson(obj, value);
}

static void codeLensOptionsFromJson(json::Object& json, CodeLensOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
}

void fromJson(json::Value&& json, CodeLensOptions& value)
{
	auto& obj = json.object();
	codeLensOptionsFromJson(obj, value);
}

static void documentLinkOptionsFromJson(json::Object& json, DocumentLinkOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
}

void fromJson(json::Value&& json, DocumentLinkOptions& value)
{
	auto& obj = json.object();
	documentLinkOptionsFromJson(obj, value);
}

static void workspaceSymbolOptionsFromJson(json::Object& json, WorkspaceSymbolOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("resolveProvider"))
		fromJson(std::move(*v), value.resolveProvider);
}

void fromJson(json::Value&& json, WorkspaceSymbolOptions& value)
{
	auto& obj = json.object();
	workspaceSymbolOptionsFromJson(obj, value);
}

static void documentFormattingOptionsFromJson(json::Object& json, DocumentFormattingOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
}

void fromJson(json::Value&& json, DocumentFormattingOptions& value)
{
	auto& obj = json.object();
	documentFormattingOptionsFromJson(obj, value);
}

static void documentRangeFormattingOptionsFromJson(json::Object& json, DocumentRangeFormattingOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("rangesSupport"))
		fromJson(std::move(*v), value.rangesSupport);
}

void fromJson(json::Value&& json, DocumentRangeFormattingOptions& value)
{
	auto& obj = json.object();
	documentRangeFormattingOptionsFromJson(obj, value);
}

static void documentOnTypeFormattingOptionsFromJson(json::Object& json, DocumentOnTypeFormattingOptions& value)
{
	fromJson(std::move(json.get("firstTriggerCharacter")), value.firstTriggerCharacter);
	if(auto* const v = json.find("moreTriggerCharacter"))
		fromJson(std::move(*v), value.moreTriggerCharacter);
}

void fromJson(json::Value&& json, DocumentOnTypeFormattingOptions& value)
{
	auto& obj = json.object();
	documentOnTypeFormattingOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentOnTypeFormattingOptions>() -> const char**
{
	static const char* properties[] = {
		"firstTriggerCharacter",
		nullptr
	};
	return properties;
}

static void renameOptionsFromJson(json::Object& json, RenameOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	if(auto* const v = json.find("prepareProvider"))
		fromJson(std::move(*v), value.prepareProvider);
}

void fromJson(json::Value&& json, RenameOptions& value)
{
	auto& obj = json.object();
	renameOptionsFromJson(obj, value);
}

static void executeCommandOptionsFromJson(json::Object& json, ExecuteCommandOptions& value)
{
	if(auto* const v = json.find("workDoneProgress"))
		fromJson(std::move(*v), value.workDoneProgress);
	fromJson(std::move(json.get("commands")), value.commands);
}

void fromJson(json::Value&& json, ExecuteCommandOptions& value)
{
	auto& obj = json.object();
	executeCommandOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ExecuteCommandOptions>() -> const char**
{
	static const char* properties[] = {
		"commands",
		nullptr
	};
	return properties;
}

static void workspaceFoldersServerCapabilitiesFromJson(json::Object& json, WorkspaceFoldersServerCapabilities& value)
{
	if(auto* const v = json.find("supported"))
		fromJson(std::move(*v), value.supported);
	if(auto* const v = json.find("changeNotifications"))
		fromJson(std::move(*v), value.changeNotifications);
}

void fromJson(json::Value&& json, WorkspaceFoldersServerCapabilities& value)
{
	auto& obj = json.object();
	workspaceFoldersServerCapabilitiesFromJson(obj, value);
}

static void fileOperationOptionsFromJson(json::Object& json, FileOperationOptions& value)
{
	if(auto* const v = json.find("didCreate"))
		fromJson(std::move(*v), value.didCreate);
	if(auto* const v = json.find("willCreate"))
		fromJson(std::move(*v), value.willCreate);
	if(auto* const v = json.find("didRename"))
		fromJson(std::move(*v), value.didRename);
	if(auto* const v = json.find("willRename"))
		fromJson(std::move(*v), value.willRename);
	if(auto* const v = json.find("didDelete"))
		fromJson(std::move(*v), value.didDelete);
	if(auto* const v = json.find("willDelete"))
		fromJson(std::move(*v), value.willDelete);
}

void fromJson(json::Value&& json, FileOperationOptions& value)
{
	auto& obj = json.object();
	fileOperationOptionsFromJson(obj, value);
}

static void workspaceOptionsFromJson(json::Object& json, WorkspaceOptions& value)
{
	if(auto* const v = json.find("workspaceFolders"))
		fromJson(std::move(*v), value.workspaceFolders);
	if(auto* const v = json.find("fileOperations"))
		fromJson(std::move(*v), value.fileOperations);
	if(auto* const v = json.find("textDocumentContent"))
		fromJson(std::move(*v), value.textDocumentContent);
}

void fromJson(json::Value&& json, WorkspaceOptions& value)
{
	auto& obj = json.object();
	workspaceOptionsFromJson(obj, value);
}

static void serverCapabilitiesFromJson(json::Object& json, ServerCapabilities& value)
{
	if(auto* const v = json.find("positionEncoding"))
		fromJson(std::move(*v), value.positionEncoding);
	if(auto* const v = json.find("textDocumentSync"))
		fromJson(std::move(*v), value.textDocumentSync);
	if(auto* const v = json.find("notebookDocumentSync"))
		fromJson(std::move(*v), value.notebookDocumentSync);
	if(auto* const v = json.find("completionProvider"))
		fromJson(std::move(*v), value.completionProvider);
	if(auto* const v = json.find("hoverProvider"))
		fromJson(std::move(*v), value.hoverProvider);
	if(auto* const v = json.find("signatureHelpProvider"))
		fromJson(std::move(*v), value.signatureHelpProvider);
	if(auto* const v = json.find("declarationProvider"))
		fromJson(std::move(*v), value.declarationProvider);
	if(auto* const v = json.find("definitionProvider"))
		fromJson(std::move(*v), value.definitionProvider);
	if(auto* const v = json.find("typeDefinitionProvider"))
		fromJson(std::move(*v), value.typeDefinitionProvider);
	if(auto* const v = json.find("implementationProvider"))
		fromJson(std::move(*v), value.implementationProvider);
	if(auto* const v = json.find("referencesProvider"))
		fromJson(std::move(*v), value.referencesProvider);
	if(auto* const v = json.find("documentHighlightProvider"))
		fromJson(std::move(*v), value.documentHighlightProvider);
	if(auto* const v = json.find("documentSymbolProvider"))
		fromJson(std::move(*v), value.documentSymbolProvider);
	if(auto* const v = json.find("codeActionProvider"))
		fromJson(std::move(*v), value.codeActionProvider);
	if(auto* const v = json.find("codeLensProvider"))
		fromJson(std::move(*v), value.codeLensProvider);
	if(auto* const v = json.find("documentLinkProvider"))
		fromJson(std::move(*v), value.documentLinkProvider);
	if(auto* const v = json.find("colorProvider"))
		fromJson(std::move(*v), value.colorProvider);
	if(auto* const v = json.find("workspaceSymbolProvider"))
		fromJson(std::move(*v), value.workspaceSymbolProvider);
	if(auto* const v = json.find("documentFormattingProvider"))
		fromJson(std::move(*v), value.documentFormattingProvider);
	if(auto* const v = json.find("documentRangeFormattingProvider"))
		fromJson(std::move(*v), value.documentRangeFormattingProvider);
	if(auto* const v = json.find("documentOnTypeFormattingProvider"))
		fromJson(std::move(*v), value.documentOnTypeFormattingProvider);
	if(auto* const v = json.find("renameProvider"))
		fromJson(std::move(*v), value.renameProvider);
	if(auto* const v = json.find("foldingRangeProvider"))
		fromJson(std::move(*v), value.foldingRangeProvider);
	if(auto* const v = json.find("selectionRangeProvider"))
		fromJson(std::move(*v), value.selectionRangeProvider);
	if(auto* const v = json.find("executeCommandProvider"))
		fromJson(std::move(*v), value.executeCommandProvider);
	if(auto* const v = json.find("callHierarchyProvider"))
		fromJson(std::move(*v), value.callHierarchyProvider);
	if(auto* const v = json.find("linkedEditingRangeProvider"))
		fromJson(std::move(*v), value.linkedEditingRangeProvider);
	if(auto* const v = json.find("semanticTokensProvider"))
		fromJson(std::move(*v), value.semanticTokensProvider);
	if(auto* const v = json.find("monikerProvider"))
		fromJson(std::move(*v), value.monikerProvider);
	if(auto* const v = json.find("typeHierarchyProvider"))
		fromJson(std::move(*v), value.typeHierarchyProvider);
	if(auto* const v = json.find("inlineValueProvider"))
		fromJson(std::move(*v), value.inlineValueProvider);
	if(auto* const v = json.find("inlayHintProvider"))
		fromJson(std::move(*v), value.inlayHintProvider);
	if(auto* const v = json.find("diagnosticProvider"))
		fromJson(std::move(*v), value.diagnosticProvider);
	if(auto* const v = json.find("inlineCompletionProvider"))
		fromJson(std::move(*v), value.inlineCompletionProvider);
	if(auto* const v = json.find("workspace"))
		fromJson(std::move(*v), value.workspace);
	if(auto* const v = json.find("experimental"))
		fromJson(std::move(*v), value.experimental);
}

void fromJson(json::Value&& json, ServerCapabilities& value)
{
	auto& obj = json.object();
	serverCapabilitiesFromJson(obj, value);
}

static void serverInfoFromJson(json::Object& json, ServerInfo& value)
{
	fromJson(std::move(json.get("name")), value.name);
	if(auto* const v = json.find("version"))
		fromJson(std::move(*v), value.version);
}

void fromJson(json::Value&& json, ServerInfo& value)
{
	auto& obj = json.object();
	serverInfoFromJson(obj, value);
}

template<>
auto requiredProperties<ServerInfo>() -> const char**
{
	static const char* properties[] = {
		"name",
		nullptr
	};
	return properties;
}

static void initializeResultFromJson(json::Object& json, InitializeResult& value)
{
	fromJson(std::move(json.get("capabilities")), value.capabilities);
	if(auto* const v = json.find("serverInfo"))
		fromJson(std::move(*v), value.serverInfo);
}

void fromJson(json::Value&& json, InitializeResult& value)
{
	auto& obj = json.object();
	initializeResultFromJson(obj, value);
}

template<>
auto requiredProperties<InitializeResult>() -> const char**
{
	static const char* properties[] = {
		"capabilities",
		nullptr
	};
	return properties;
}

static void initializeErrorFromJson(json::Object& json, InitializeError& value)
{
	fromJson(std::move(json.get("retry")), value.retry);
}

void fromJson(json::Value&& json, InitializeError& value)
{
	auto& obj = json.object();
	initializeErrorFromJson(obj, value);
}

template<>
auto requiredProperties<InitializeError>() -> const char**
{
	static const char* properties[] = {
		"retry",
		nullptr
	};
	return properties;
}

static void initializedParamsFromJson(json::Object& json, InitializedParams& value)
{
}

void fromJson(json::Value&& json, InitializedParams& value)
{
	auto& obj = json.object();
	initializedParamsFromJson(obj, value);
}

static void didChangeConfigurationParamsFromJson(json::Object& json, DidChangeConfigurationParams& value)
{
	fromJson(std::move(json.get("settings")), value.settings);
}

void fromJson(json::Value&& json, DidChangeConfigurationParams& value)
{
	auto& obj = json.object();
	didChangeConfigurationParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeConfigurationParams>() -> const char**
{
	static const char* properties[] = {
		"settings",
		nullptr
	};
	return properties;
}

static void didChangeConfigurationRegistrationOptionsFromJson(json::Object& json, DidChangeConfigurationRegistrationOptions& value)
{
	if(auto* const v = json.find("section"))
		fromJson(std::move(*v), value.section);
}

void fromJson(json::Value&& json, DidChangeConfigurationRegistrationOptions& value)
{
	auto& obj = json.object();
	didChangeConfigurationRegistrationOptionsFromJson(obj, value);
}

static void showMessageParamsFromJson(json::Object& json, ShowMessageParams& value)
{
	fromJson(std::move(json.get("type")), value.type);
	fromJson(std::move(json.get("message")), value.message);
}

void fromJson(json::Value&& json, ShowMessageParams& value)
{
	auto& obj = json.object();
	showMessageParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ShowMessageParams>() -> const char**
{
	static const char* properties[] = {
		"type",
		"message",
		nullptr
	};
	return properties;
}

static void messageActionItemFromJson(json::Object& json, MessageActionItem& value)
{
	fromJson(std::move(json.get("title")), value.title);
}

void fromJson(json::Value&& json, MessageActionItem& value)
{
	auto& obj = json.object();
	messageActionItemFromJson(obj, value);
}

template<>
auto requiredProperties<MessageActionItem>() -> const char**
{
	static const char* properties[] = {
		"title",
		nullptr
	};
	return properties;
}

static void showMessageRequestParamsFromJson(json::Object& json, ShowMessageRequestParams& value)
{
	fromJson(std::move(json.get("type")), value.type);
	fromJson(std::move(json.get("message")), value.message);
	if(auto* const v = json.find("actions"))
		fromJson(std::move(*v), value.actions);
}

void fromJson(json::Value&& json, ShowMessageRequestParams& value)
{
	auto& obj = json.object();
	showMessageRequestParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ShowMessageRequestParams>() -> const char**
{
	static const char* properties[] = {
		"type",
		"message",
		nullptr
	};
	return properties;
}

static void logMessageParamsFromJson(json::Object& json, LogMessageParams& value)
{
	fromJson(std::move(json.get("type")), value.type);
	fromJson(std::move(json.get("message")), value.message);
}

void fromJson(json::Value&& json, LogMessageParams& value)
{
	auto& obj = json.object();
	logMessageParamsFromJson(obj, value);
}

template<>
auto requiredProperties<LogMessageParams>() -> const char**
{
	static const char* properties[] = {
		"type",
		"message",
		nullptr
	};
	return properties;
}

static void didOpenTextDocumentParamsFromJson(json::Object& json, DidOpenTextDocumentParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, DidOpenTextDocumentParams& value)
{
	auto& obj = json.object();
	didOpenTextDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidOpenTextDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void didChangeTextDocumentParamsFromJson(json::Object& json, DidChangeTextDocumentParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("contentChanges")), value.contentChanges);
}

void fromJson(json::Value&& json, DidChangeTextDocumentParams& value)
{
	auto& obj = json.object();
	didChangeTextDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeTextDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"contentChanges",
		nullptr
	};
	return properties;
}

static void textDocumentChangeRegistrationOptionsFromJson(json::Object& json, TextDocumentChangeRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	fromJson(std::move(json.get("syncKind")), value.syncKind);
}

void fromJson(json::Value&& json, TextDocumentChangeRegistrationOptions& value)
{
	auto& obj = json.object();
	textDocumentChangeRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentChangeRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		"syncKind",
		nullptr
	};
	return properties;
}

static void didCloseTextDocumentParamsFromJson(json::Object& json, DidCloseTextDocumentParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, DidCloseTextDocumentParams& value)
{
	auto& obj = json.object();
	didCloseTextDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidCloseTextDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void didSaveTextDocumentParamsFromJson(json::Object& json, DidSaveTextDocumentParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	if(auto* const v = json.find("text"))
		fromJson(std::move(*v), value.text);
}

void fromJson(json::Value&& json, DidSaveTextDocumentParams& value)
{
	auto& obj = json.object();
	didSaveTextDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidSaveTextDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void textDocumentSaveRegistrationOptionsFromJson(json::Object& json, TextDocumentSaveRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	saveOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, TextDocumentSaveRegistrationOptions& value)
{
	auto& obj = json.object();
	textDocumentSaveRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<TextDocumentSaveRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void willSaveTextDocumentParamsFromJson(json::Object& json, WillSaveTextDocumentParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("reason")), value.reason);
}

void fromJson(json::Value&& json, WillSaveTextDocumentParams& value)
{
	auto& obj = json.object();
	willSaveTextDocumentParamsFromJson(obj, value);
}

template<>
auto requiredProperties<WillSaveTextDocumentParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"reason",
		nullptr
	};
	return properties;
}

static void fileEventFromJson(json::Object& json, FileEvent& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("type")), value.type);
}

void fromJson(json::Value&& json, FileEvent& value)
{
	auto& obj = json.object();
	fileEventFromJson(obj, value);
}

template<>
auto requiredProperties<FileEvent>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"type",
		nullptr
	};
	return properties;
}

static void didChangeWatchedFilesParamsFromJson(json::Object& json, DidChangeWatchedFilesParams& value)
{
	fromJson(std::move(json.get("changes")), value.changes);
}

void fromJson(json::Value&& json, DidChangeWatchedFilesParams& value)
{
	auto& obj = json.object();
	didChangeWatchedFilesParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeWatchedFilesParams>() -> const char**
{
	static const char* properties[] = {
		"changes",
		nullptr
	};
	return properties;
}

static void fileSystemWatcherFromJson(json::Object& json, FileSystemWatcher& value)
{
	fromJson(std::move(json.get("globPattern")), value.globPattern);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
}

void fromJson(json::Value&& json, FileSystemWatcher& value)
{
	auto& obj = json.object();
	fileSystemWatcherFromJson(obj, value);
}

template<>
auto requiredProperties<FileSystemWatcher>() -> const char**
{
	static const char* properties[] = {
		"globPattern",
		nullptr
	};
	return properties;
}

static void didChangeWatchedFilesRegistrationOptionsFromJson(json::Object& json, DidChangeWatchedFilesRegistrationOptions& value)
{
	fromJson(std::move(json.get("watchers")), value.watchers);
}

void fromJson(json::Value&& json, DidChangeWatchedFilesRegistrationOptions& value)
{
	auto& obj = json.object();
	didChangeWatchedFilesRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DidChangeWatchedFilesRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"watchers",
		nullptr
	};
	return properties;
}

static void publishDiagnosticsParamsFromJson(json::Object& json, PublishDiagnosticsParams& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
	fromJson(std::move(json.get("diagnostics")), value.diagnostics);
	if(auto* const v = json.find("version"))
		fromJson(std::move(*v), value.version);
}

void fromJson(json::Value&& json, PublishDiagnosticsParams& value)
{
	auto& obj = json.object();
	publishDiagnosticsParamsFromJson(obj, value);
}

template<>
auto requiredProperties<PublishDiagnosticsParams>() -> const char**
{
	static const char* properties[] = {
		"uri",
		"diagnostics",
		nullptr
	};
	return properties;
}

static void completionContextFromJson(json::Object& json, CompletionContext& value)
{
	fromJson(std::move(json.get("triggerKind")), value.triggerKind);
	if(auto* const v = json.find("triggerCharacter"))
		fromJson(std::move(*v), value.triggerCharacter);
}

void fromJson(json::Value&& json, CompletionContext& value)
{
	auto& obj = json.object();
	completionContextFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionContext>() -> const char**
{
	static const char* properties[] = {
		"triggerKind",
		nullptr
	};
	return properties;
}

static void completionParamsFromJson(json::Object& json, CompletionParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	if(auto* const v = json.find("context"))
		fromJson(std::move(*v), value.context);
}

void fromJson(json::Value&& json, CompletionParams& value)
{
	auto& obj = json.object();
	completionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void completionItemLabelDetailsFromJson(json::Object& json, CompletionItemLabelDetails& value)
{
	if(auto* const v = json.find("detail"))
		fromJson(std::move(*v), value.detail);
	if(auto* const v = json.find("description"))
		fromJson(std::move(*v), value.description);
}

void fromJson(json::Value&& json, CompletionItemLabelDetails& value)
{
	auto& obj = json.object();
	completionItemLabelDetailsFromJson(obj, value);
}

static void insertReplaceEditFromJson(json::Object& json, InsertReplaceEdit& value)
{
	fromJson(std::move(json.get("newText")), value.newText);
	fromJson(std::move(json.get("insert")), value.insert);
	fromJson(std::move(json.get("replace")), value.replace);
}

void fromJson(json::Value&& json, InsertReplaceEdit& value)
{
	auto& obj = json.object();
	insertReplaceEditFromJson(obj, value);
}

template<>
auto requiredProperties<InsertReplaceEdit>() -> const char**
{
	static const char* properties[] = {
		"newText",
		"insert",
		"replace",
		nullptr
	};
	return properties;
}

static void completionItemFromJson(json::Object& json, CompletionItem& value)
{
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("labelDetails"))
		fromJson(std::move(*v), value.labelDetails);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("detail"))
		fromJson(std::move(*v), value.detail);
	if(auto* const v = json.find("documentation"))
		fromJson(std::move(*v), value.documentation);
	if(auto* const v = json.find("deprecated"))
		fromJson(std::move(*v), value.deprecated);
	if(auto* const v = json.find("preselect"))
		fromJson(std::move(*v), value.preselect);
	if(auto* const v = json.find("sortText"))
		fromJson(std::move(*v), value.sortText);
	if(auto* const v = json.find("filterText"))
		fromJson(std::move(*v), value.filterText);
	if(auto* const v = json.find("insertText"))
		fromJson(std::move(*v), value.insertText);
	if(auto* const v = json.find("insertTextFormat"))
		fromJson(std::move(*v), value.insertTextFormat);
	if(auto* const v = json.find("insertTextMode"))
		fromJson(std::move(*v), value.insertTextMode);
	if(auto* const v = json.find("textEdit"))
		fromJson(std::move(*v), value.textEdit);
	if(auto* const v = json.find("textEditText"))
		fromJson(std::move(*v), value.textEditText);
	if(auto* const v = json.find("additionalTextEdits"))
		fromJson(std::move(*v), value.additionalTextEdits);
	if(auto* const v = json.find("commitCharacters"))
		fromJson(std::move(*v), value.commitCharacters);
	if(auto* const v = json.find("command"))
		fromJson(std::move(*v), value.command);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, CompletionItem& value)
{
	auto& obj = json.object();
	completionItemFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionItem>() -> const char**
{
	static const char* properties[] = {
		"label",
		nullptr
	};
	return properties;
}

static void editRangeWithInsertReplaceFromJson(json::Object& json, EditRangeWithInsertReplace& value)
{
	fromJson(std::move(json.get("insert")), value.insert);
	fromJson(std::move(json.get("replace")), value.replace);
}

void fromJson(json::Value&& json, EditRangeWithInsertReplace& value)
{
	auto& obj = json.object();
	editRangeWithInsertReplaceFromJson(obj, value);
}

template<>
auto requiredProperties<EditRangeWithInsertReplace>() -> const char**
{
	static const char* properties[] = {
		"insert",
		"replace",
		nullptr
	};
	return properties;
}

static void completionItemDefaultsFromJson(json::Object& json, CompletionItemDefaults& value)
{
	if(auto* const v = json.find("commitCharacters"))
		fromJson(std::move(*v), value.commitCharacters);
	if(auto* const v = json.find("editRange"))
		fromJson(std::move(*v), value.editRange);
	if(auto* const v = json.find("insertTextFormat"))
		fromJson(std::move(*v), value.insertTextFormat);
	if(auto* const v = json.find("insertTextMode"))
		fromJson(std::move(*v), value.insertTextMode);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, CompletionItemDefaults& value)
{
	auto& obj = json.object();
	completionItemDefaultsFromJson(obj, value);
}

static void completionItemApplyKindsFromJson(json::Object& json, CompletionItemApplyKinds& value)
{
	if(auto* const v = json.find("commitCharacters"))
		fromJson(std::move(*v), value.commitCharacters);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, CompletionItemApplyKinds& value)
{
	auto& obj = json.object();
	completionItemApplyKindsFromJson(obj, value);
}

static void completionListFromJson(json::Object& json, CompletionList& value)
{
	fromJson(std::move(json.get("isIncomplete")), value.isIncomplete);
	fromJson(std::move(json.get("items")), value.items);
	if(auto* const v = json.find("itemDefaults"))
		fromJson(std::move(*v), value.itemDefaults);
	if(auto* const v = json.find("applyKind"))
		fromJson(std::move(*v), value.applyKind);
}

void fromJson(json::Value&& json, CompletionList& value)
{
	auto& obj = json.object();
	completionListFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionList>() -> const char**
{
	static const char* properties[] = {
		"isIncomplete",
		"items",
		nullptr
	};
	return properties;
}

static void completionRegistrationOptionsFromJson(json::Object& json, CompletionRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	completionOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, CompletionRegistrationOptions& value)
{
	auto& obj = json.object();
	completionRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CompletionRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void hoverParamsFromJson(json::Object& json, HoverParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, HoverParams& value)
{
	auto& obj = json.object();
	hoverParamsFromJson(obj, value);
}

template<>
auto requiredProperties<HoverParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void markedStringWithLanguageFromJson(json::Object& json, MarkedStringWithLanguage& value)
{
	fromJson(std::move(json.get("language")), value.language);
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, MarkedStringWithLanguage& value)
{
	auto& obj = json.object();
	markedStringWithLanguageFromJson(obj, value);
}

template<>
auto requiredProperties<MarkedStringWithLanguage>() -> const char**
{
	static const char* properties[] = {
		"language",
		"value",
		nullptr
	};
	return properties;
}

static void hoverFromJson(json::Object& json, Hover& value)
{
	fromJson(std::move(json.get("contents")), value.contents);
	if(auto* const v = json.find("range"))
		fromJson(std::move(*v), value.range);
}

void fromJson(json::Value&& json, Hover& value)
{
	auto& obj = json.object();
	hoverFromJson(obj, value);
}

template<>
auto requiredProperties<Hover>() -> const char**
{
	static const char* properties[] = {
		"contents",
		nullptr
	};
	return properties;
}

static void hoverRegistrationOptionsFromJson(json::Object& json, HoverRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	hoverOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, HoverRegistrationOptions& value)
{
	auto& obj = json.object();
	hoverRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<HoverRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void parameterInformationFromJson(json::Object& json, ParameterInformation& value)
{
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("documentation"))
		fromJson(std::move(*v), value.documentation);
}

void fromJson(json::Value&& json, ParameterInformation& value)
{
	auto& obj = json.object();
	parameterInformationFromJson(obj, value);
}

template<>
auto requiredProperties<ParameterInformation>() -> const char**
{
	static const char* properties[] = {
		"label",
		nullptr
	};
	return properties;
}

static void signatureInformationFromJson(json::Object& json, SignatureInformation& value)
{
	fromJson(std::move(json.get("label")), value.label);
	if(auto* const v = json.find("documentation"))
		fromJson(std::move(*v), value.documentation);
	if(auto* const v = json.find("parameters"))
		fromJson(std::move(*v), value.parameters);
	if(auto* const v = json.find("activeParameter"))
		fromJson(std::move(*v), value.activeParameter);
}

void fromJson(json::Value&& json, SignatureInformation& value)
{
	auto& obj = json.object();
	signatureInformationFromJson(obj, value);
}

template<>
auto requiredProperties<SignatureInformation>() -> const char**
{
	static const char* properties[] = {
		"label",
		nullptr
	};
	return properties;
}

static void signatureHelpFromJson(json::Object& json, SignatureHelp& value)
{
	fromJson(std::move(json.get("signatures")), value.signatures);
	if(auto* const v = json.find("activeSignature"))
		fromJson(std::move(*v), value.activeSignature);
	if(auto* const v = json.find("activeParameter"))
		fromJson(std::move(*v), value.activeParameter);
}

void fromJson(json::Value&& json, SignatureHelp& value)
{
	auto& obj = json.object();
	signatureHelpFromJson(obj, value);
}

template<>
auto requiredProperties<SignatureHelp>() -> const char**
{
	static const char* properties[] = {
		"signatures",
		nullptr
	};
	return properties;
}

static void signatureHelpContextFromJson(json::Object& json, SignatureHelpContext& value)
{
	fromJson(std::move(json.get("triggerKind")), value.triggerKind);
	fromJson(std::move(json.get("isRetrigger")), value.isRetrigger);
	if(auto* const v = json.find("triggerCharacter"))
		fromJson(std::move(*v), value.triggerCharacter);
	if(auto* const v = json.find("activeSignatureHelp"))
		fromJson(std::move(*v), value.activeSignatureHelp);
}

void fromJson(json::Value&& json, SignatureHelpContext& value)
{
	auto& obj = json.object();
	signatureHelpContextFromJson(obj, value);
}

template<>
auto requiredProperties<SignatureHelpContext>() -> const char**
{
	static const char* properties[] = {
		"triggerKind",
		"isRetrigger",
		nullptr
	};
	return properties;
}

static void signatureHelpParamsFromJson(json::Object& json, SignatureHelpParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("context"))
		fromJson(std::move(*v), value.context);
}

void fromJson(json::Value&& json, SignatureHelpParams& value)
{
	auto& obj = json.object();
	signatureHelpParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SignatureHelpParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void signatureHelpRegistrationOptionsFromJson(json::Object& json, SignatureHelpRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	signatureHelpOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, SignatureHelpRegistrationOptions& value)
{
	auto& obj = json.object();
	signatureHelpRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<SignatureHelpRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void definitionParamsFromJson(json::Object& json, DefinitionParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, DefinitionParams& value)
{
	auto& obj = json.object();
	definitionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DefinitionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void definitionRegistrationOptionsFromJson(json::Object& json, DefinitionRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	definitionOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DefinitionRegistrationOptions& value)
{
	auto& obj = json.object();
	definitionRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DefinitionRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void referenceContextFromJson(json::Object& json, ReferenceContext& value)
{
	fromJson(std::move(json.get("includeDeclaration")), value.includeDeclaration);
}

void fromJson(json::Value&& json, ReferenceContext& value)
{
	auto& obj = json.object();
	referenceContextFromJson(obj, value);
}

template<>
auto requiredProperties<ReferenceContext>() -> const char**
{
	static const char* properties[] = {
		"includeDeclaration",
		nullptr
	};
	return properties;
}

static void referenceParamsFromJson(json::Object& json, ReferenceParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("context")), value.context);
}

void fromJson(json::Value&& json, ReferenceParams& value)
{
	auto& obj = json.object();
	referenceParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ReferenceParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		"context",
		nullptr
	};
	return properties;
}

static void referenceRegistrationOptionsFromJson(json::Object& json, ReferenceRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	referenceOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, ReferenceRegistrationOptions& value)
{
	auto& obj = json.object();
	referenceRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ReferenceRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentHighlightParamsFromJson(json::Object& json, DocumentHighlightParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
}

void fromJson(json::Value&& json, DocumentHighlightParams& value)
{
	auto& obj = json.object();
	documentHighlightParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentHighlightParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void documentHighlightFromJson(json::Object& json, DocumentHighlight& value)
{
	fromJson(std::move(json.get("range")), value.range);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
}

void fromJson(json::Value&& json, DocumentHighlight& value)
{
	auto& obj = json.object();
	documentHighlightFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentHighlight>() -> const char**
{
	static const char* properties[] = {
		"range",
		nullptr
	};
	return properties;
}

static void documentHighlightRegistrationOptionsFromJson(json::Object& json, DocumentHighlightRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentHighlightOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentHighlightRegistrationOptions& value)
{
	auto& obj = json.object();
	documentHighlightRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentHighlightRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentSymbolParamsFromJson(json::Object& json, DocumentSymbolParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, DocumentSymbolParams& value)
{
	auto& obj = json.object();
	documentSymbolParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentSymbolParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void baseSymbolInformationFromJson(json::Object& json, BaseSymbolInformation& value)
{
	fromJson(std::move(json.get("name")), value.name);
	fromJson(std::move(json.get("kind")), value.kind);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("containerName"))
		fromJson(std::move(*v), value.containerName);
}

void fromJson(json::Value&& json, BaseSymbolInformation& value)
{
	auto& obj = json.object();
	baseSymbolInformationFromJson(obj, value);
}

template<>
auto requiredProperties<BaseSymbolInformation>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		nullptr
	};
	return properties;
}

static void symbolInformationFromJson(json::Object& json, SymbolInformation& value)
{
	baseSymbolInformationFromJson(json, value);
	fromJson(std::move(json.get("location")), value.location);
	if(auto* const v = json.find("deprecated"))
		fromJson(std::move(*v), value.deprecated);
}

void fromJson(json::Value&& json, SymbolInformation& value)
{
	auto& obj = json.object();
	symbolInformationFromJson(obj, value);
}

template<>
auto requiredProperties<SymbolInformation>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		"location",
		nullptr
	};
	return properties;
}

static void documentSymbolFromJson(json::Object& json, DocumentSymbol& value)
{
	fromJson(std::move(json.get("name")), value.name);
	fromJson(std::move(json.get("kind")), value.kind);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("selectionRange")), value.selectionRange);
	if(auto* const v = json.find("detail"))
		fromJson(std::move(*v), value.detail);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
	if(auto* const v = json.find("deprecated"))
		fromJson(std::move(*v), value.deprecated);
	if(auto* const v = json.find("children"))
		fromJson(std::move(*v), value.children);
}

void fromJson(json::Value&& json, DocumentSymbol& value)
{
	auto& obj = json.object();
	documentSymbolFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentSymbol>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		"range",
		"selectionRange",
		nullptr
	};
	return properties;
}

static void documentSymbolRegistrationOptionsFromJson(json::Object& json, DocumentSymbolRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentSymbolOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentSymbolRegistrationOptions& value)
{
	auto& obj = json.object();
	documentSymbolRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentSymbolRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void codeActionContextFromJson(json::Object& json, CodeActionContext& value)
{
	fromJson(std::move(json.get("diagnostics")), value.diagnostics);
	if(auto* const v = json.find("only"))
		fromJson(std::move(*v), value.only);
	if(auto* const v = json.find("triggerKind"))
		fromJson(std::move(*v), value.triggerKind);
}

void fromJson(json::Value&& json, CodeActionContext& value)
{
	auto& obj = json.object();
	codeActionContextFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionContext>() -> const char**
{
	static const char* properties[] = {
		"diagnostics",
		nullptr
	};
	return properties;
}

static void codeActionParamsFromJson(json::Object& json, CodeActionParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("context")), value.context);
}

void fromJson(json::Value&& json, CodeActionParams& value)
{
	auto& obj = json.object();
	codeActionParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"range",
		"context",
		nullptr
	};
	return properties;
}

static void codeActionDisabledFromJson(json::Object& json, CodeActionDisabled& value)
{
	fromJson(std::move(json.get("reason")), value.reason);
}

void fromJson(json::Value&& json, CodeActionDisabled& value)
{
	auto& obj = json.object();
	codeActionDisabledFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionDisabled>() -> const char**
{
	static const char* properties[] = {
		"reason",
		nullptr
	};
	return properties;
}

static void codeActionFromJson(json::Object& json, CodeAction& value)
{
	fromJson(std::move(json.get("title")), value.title);
	if(auto* const v = json.find("kind"))
		fromJson(std::move(*v), value.kind);
	if(auto* const v = json.find("diagnostics"))
		fromJson(std::move(*v), value.diagnostics);
	if(auto* const v = json.find("isPreferred"))
		fromJson(std::move(*v), value.isPreferred);
	if(auto* const v = json.find("disabled"))
		fromJson(std::move(*v), value.disabled);
	if(auto* const v = json.find("edit"))
		fromJson(std::move(*v), value.edit);
	if(auto* const v = json.find("command"))
		fromJson(std::move(*v), value.command);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
	if(auto* const v = json.find("tags"))
		fromJson(std::move(*v), value.tags);
}

void fromJson(json::Value&& json, CodeAction& value)
{
	auto& obj = json.object();
	codeActionFromJson(obj, value);
}

template<>
auto requiredProperties<CodeAction>() -> const char**
{
	static const char* properties[] = {
		"title",
		nullptr
	};
	return properties;
}

static void codeActionRegistrationOptionsFromJson(json::Object& json, CodeActionRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	codeActionOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, CodeActionRegistrationOptions& value)
{
	auto& obj = json.object();
	codeActionRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CodeActionRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void workspaceSymbolParamsFromJson(json::Object& json, WorkspaceSymbolParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("query")), value.query);
}

void fromJson(json::Value&& json, WorkspaceSymbolParams& value)
{
	auto& obj = json.object();
	workspaceSymbolParamsFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceSymbolParams>() -> const char**
{
	static const char* properties[] = {
		"query",
		nullptr
	};
	return properties;
}

static void locationUriOnlyFromJson(json::Object& json, LocationUriOnly& value)
{
	fromJson(std::move(json.get("uri")), value.uri);
}

void fromJson(json::Value&& json, LocationUriOnly& value)
{
	auto& obj = json.object();
	locationUriOnlyFromJson(obj, value);
}

template<>
auto requiredProperties<LocationUriOnly>() -> const char**
{
	static const char* properties[] = {
		"uri",
		nullptr
	};
	return properties;
}

static void workspaceSymbolFromJson(json::Object& json, WorkspaceSymbol& value)
{
	baseSymbolInformationFromJson(json, value);
	fromJson(std::move(json.get("location")), value.location);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, WorkspaceSymbol& value)
{
	auto& obj = json.object();
	workspaceSymbolFromJson(obj, value);
}

template<>
auto requiredProperties<WorkspaceSymbol>() -> const char**
{
	static const char* properties[] = {
		"name",
		"kind",
		"location",
		nullptr
	};
	return properties;
}

static void workspaceSymbolRegistrationOptionsFromJson(json::Object& json, WorkspaceSymbolRegistrationOptions& value)
{
	workspaceSymbolOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, WorkspaceSymbolRegistrationOptions& value)
{
	auto& obj = json.object();
	workspaceSymbolRegistrationOptionsFromJson(obj, value);
}

static void codeLensParamsFromJson(json::Object& json, CodeLensParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, CodeLensParams& value)
{
	auto& obj = json.object();
	codeLensParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CodeLensParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void codeLensFromJson(json::Object& json, CodeLens& value)
{
	fromJson(std::move(json.get("range")), value.range);
	if(auto* const v = json.find("command"))
		fromJson(std::move(*v), value.command);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, CodeLens& value)
{
	auto& obj = json.object();
	codeLensFromJson(obj, value);
}

template<>
auto requiredProperties<CodeLens>() -> const char**
{
	static const char* properties[] = {
		"range",
		nullptr
	};
	return properties;
}

static void codeLensRegistrationOptionsFromJson(json::Object& json, CodeLensRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	codeLensOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, CodeLensRegistrationOptions& value)
{
	auto& obj = json.object();
	codeLensRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<CodeLensRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentLinkParamsFromJson(json::Object& json, DocumentLinkParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	if(auto* const v = json.find("partialResultToken"))
		fromJson(std::move(*v), value.partialResultToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
}

void fromJson(json::Value&& json, DocumentLinkParams& value)
{
	auto& obj = json.object();
	documentLinkParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentLinkParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		nullptr
	};
	return properties;
}

static void documentLinkFromJson(json::Object& json, DocumentLink& value)
{
	fromJson(std::move(json.get("range")), value.range);
	if(auto* const v = json.find("target"))
		fromJson(std::move(*v), value.target);
	if(auto* const v = json.find("tooltip"))
		fromJson(std::move(*v), value.tooltip);
	if(auto* const v = json.find("data"))
		fromJson(std::move(*v), value.data);
}

void fromJson(json::Value&& json, DocumentLink& value)
{
	auto& obj = json.object();
	documentLinkFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentLink>() -> const char**
{
	static const char* properties[] = {
		"range",
		nullptr
	};
	return properties;
}

static void documentLinkRegistrationOptionsFromJson(json::Object& json, DocumentLinkRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentLinkOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentLinkRegistrationOptions& value)
{
	auto& obj = json.object();
	documentLinkRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentLinkRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void formattingOptionsFromJson(json::Object& json, FormattingOptions& value)
{
	fromJson(std::move(json.get("tabSize")), value.tabSize);
	fromJson(std::move(json.get("insertSpaces")), value.insertSpaces);
	if(auto* const v = json.find("trimTrailingWhitespace"))
		fromJson(std::move(*v), value.trimTrailingWhitespace);
	if(auto* const v = json.find("insertFinalNewline"))
		fromJson(std::move(*v), value.insertFinalNewline);
	if(auto* const v = json.find("trimFinalNewlines"))
		fromJson(std::move(*v), value.trimFinalNewlines);
}

void fromJson(json::Value&& json, FormattingOptions& value)
{
	auto& obj = json.object();
	formattingOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<FormattingOptions>() -> const char**
{
	static const char* properties[] = {
		"tabSize",
		"insertSpaces",
		nullptr
	};
	return properties;
}

static void documentFormattingParamsFromJson(json::Object& json, DocumentFormattingParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("options")), value.options);
}

void fromJson(json::Value&& json, DocumentFormattingParams& value)
{
	auto& obj = json.object();
	documentFormattingParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentFormattingParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"options",
		nullptr
	};
	return properties;
}

static void documentFormattingRegistrationOptionsFromJson(json::Object& json, DocumentFormattingRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentFormattingOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentFormattingRegistrationOptions& value)
{
	auto& obj = json.object();
	documentFormattingRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentFormattingRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentRangeFormattingParamsFromJson(json::Object& json, DocumentRangeFormattingParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("options")), value.options);
}

void fromJson(json::Value&& json, DocumentRangeFormattingParams& value)
{
	auto& obj = json.object();
	documentRangeFormattingParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentRangeFormattingParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"range",
		"options",
		nullptr
	};
	return properties;
}

static void documentRangeFormattingRegistrationOptionsFromJson(json::Object& json, DocumentRangeFormattingRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentRangeFormattingOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentRangeFormattingRegistrationOptions& value)
{
	auto& obj = json.object();
	documentRangeFormattingRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentRangeFormattingRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void documentRangesFormattingParamsFromJson(json::Object& json, DocumentRangesFormattingParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("ranges")), value.ranges);
	fromJson(std::move(json.get("options")), value.options);
}

void fromJson(json::Value&& json, DocumentRangesFormattingParams& value)
{
	auto& obj = json.object();
	documentRangesFormattingParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentRangesFormattingParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"ranges",
		"options",
		nullptr
	};
	return properties;
}

static void documentOnTypeFormattingParamsFromJson(json::Object& json, DocumentOnTypeFormattingParams& value)
{
	fromJson(std::move(json.get("textDocument")), value.textDocument);
	fromJson(std::move(json.get("position")), value.position);
	fromJson(std::move(json.get("ch")), value.ch);
	fromJson(std::move(json.get("options")), value.options);
}

void fromJson(json::Value&& json, DocumentOnTypeFormattingParams& value)
{
	auto& obj = json.object();
	documentOnTypeFormattingParamsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentOnTypeFormattingParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		"ch",
		"options",
		nullptr
	};
	return properties;
}

static void documentOnTypeFormattingRegistrationOptionsFromJson(json::Object& json, DocumentOnTypeFormattingRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	documentOnTypeFormattingOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, DocumentOnTypeFormattingRegistrationOptions& value)
{
	auto& obj = json.object();
	documentOnTypeFormattingRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentOnTypeFormattingRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		"firstTriggerCharacter",
		nullptr
	};
	return properties;
}

static void renameParamsFromJson(json::Object& json, RenameParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("newName")), value.newName);
}

void fromJson(json::Value&& json, RenameParams& value)
{
	auto& obj = json.object();
	renameParamsFromJson(obj, value);
}

template<>
auto requiredProperties<RenameParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		"newName",
		nullptr
	};
	return properties;
}

static void renameRegistrationOptionsFromJson(json::Object& json, RenameRegistrationOptions& value)
{
	textDocumentRegistrationOptionsFromJson(json, value);
	renameOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, RenameRegistrationOptions& value)
{
	auto& obj = json.object();
	renameRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<RenameRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"documentSelector",
		nullptr
	};
	return properties;
}

static void prepareRenameParamsFromJson(json::Object& json, PrepareRenameParams& value)
{
	textDocumentPositionParamsFromJson(json, value);
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
}

void fromJson(json::Value&& json, PrepareRenameParams& value)
{
	auto& obj = json.object();
	prepareRenameParamsFromJson(obj, value);
}

template<>
auto requiredProperties<PrepareRenameParams>() -> const char**
{
	static const char* properties[] = {
		"textDocument",
		"position",
		nullptr
	};
	return properties;
}

static void executeCommandParamsFromJson(json::Object& json, ExecuteCommandParams& value)
{
	if(auto* const v = json.find("workDoneToken"))
		fromJson(std::move(*v), value.workDoneToken);
	fromJson(std::move(json.get("command")), value.command);
	if(auto* const v = json.find("arguments"))
		fromJson(std::move(*v), value.arguments);
}

void fromJson(json::Value&& json, ExecuteCommandParams& value)
{
	auto& obj = json.object();
	executeCommandParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ExecuteCommandParams>() -> const char**
{
	static const char* properties[] = {
		"command",
		nullptr
	};
	return properties;
}

static void executeCommandRegistrationOptionsFromJson(json::Object& json, ExecuteCommandRegistrationOptions& value)
{
	executeCommandOptionsFromJson(json, value);
}

void fromJson(json::Value&& json, ExecuteCommandRegistrationOptions& value)
{
	auto& obj = json.object();
	executeCommandRegistrationOptionsFromJson(obj, value);
}

template<>
auto requiredProperties<ExecuteCommandRegistrationOptions>() -> const char**
{
	static const char* properties[] = {
		"commands",
		nullptr
	};
	return properties;
}

static void workspaceEditMetadataFromJson(json::Object& json, WorkspaceEditMetadata& value)
{
	if(auto* const v = json.find("isRefactoring"))
		fromJson(std::move(*v), value.isRefactoring);
}

void fromJson(json::Value&& json, WorkspaceEditMetadata& value)
{
	auto& obj = json.object();
	workspaceEditMetadataFromJson(obj, value);
}

static void applyWorkspaceEditParamsFromJson(json::Object& json, ApplyWorkspaceEditParams& value)
{
	fromJson(std::move(json.get("edit")), value.edit);
	if(auto* const v = json.find("label"))
		fromJson(std::move(*v), value.label);
	if(auto* const v = json.find("metadata"))
		fromJson(std::move(*v), value.metadata);
}

void fromJson(json::Value&& json, ApplyWorkspaceEditParams& value)
{
	auto& obj = json.object();
	applyWorkspaceEditParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ApplyWorkspaceEditParams>() -> const char**
{
	static const char* properties[] = {
		"edit",
		nullptr
	};
	return properties;
}

static void applyWorkspaceEditResultFromJson(json::Object& json, ApplyWorkspaceEditResult& value)
{
	fromJson(std::move(json.get("applied")), value.applied);
	if(auto* const v = json.find("failureReason"))
		fromJson(std::move(*v), value.failureReason);
	if(auto* const v = json.find("failedChange"))
		fromJson(std::move(*v), value.failedChange);
}

void fromJson(json::Value&& json, ApplyWorkspaceEditResult& value)
{
	auto& obj = json.object();
	applyWorkspaceEditResultFromJson(obj, value);
}

template<>
auto requiredProperties<ApplyWorkspaceEditResult>() -> const char**
{
	static const char* properties[] = {
		"applied",
		nullptr
	};
	return properties;
}

static void workDoneProgressBeginFromJson(json::Object& json, WorkDoneProgressBegin& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "begin")
		throw json::TypeError("Invalid value for literal property 'kind'");
	fromJson(std::move(json.get("title")), value.title);
	if(auto* const v = json.find("cancellable"))
		fromJson(std::move(*v), value.cancellable);
	if(auto* const v = json.find("message"))
		fromJson(std::move(*v), value.message);
	if(auto* const v = json.find("percentage"))
		fromJson(std::move(*v), value.percentage);
}

void fromJson(json::Value&& json, WorkDoneProgressBegin& value)
{
	auto& obj = json.object();
	workDoneProgressBeginFromJson(obj, value);
}

template<>
auto requiredProperties<WorkDoneProgressBegin>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"title",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<WorkDoneProgressBegin>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "begin"},
		{nullptr, {}}
	};
	return properties;
}

static void workDoneProgressReportFromJson(json::Object& json, WorkDoneProgressReport& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "report")
		throw json::TypeError("Invalid value for literal property 'kind'");
	if(auto* const v = json.find("cancellable"))
		fromJson(std::move(*v), value.cancellable);
	if(auto* const v = json.find("message"))
		fromJson(std::move(*v), value.message);
	if(auto* const v = json.find("percentage"))
		fromJson(std::move(*v), value.percentage);
}

void fromJson(json::Value&& json, WorkDoneProgressReport& value)
{
	auto& obj = json.object();
	workDoneProgressReportFromJson(obj, value);
}

template<>
auto requiredProperties<WorkDoneProgressReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<WorkDoneProgressReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "report"},
		{nullptr, {}}
	};
	return properties;
}

static void workDoneProgressEndFromJson(json::Object& json, WorkDoneProgressEnd& value)
{
	fromJson(std::move(json.get("kind")), value.kind);
	if(value.kind != "end")
		throw json::TypeError("Invalid value for literal property 'kind'");
	if(auto* const v = json.find("message"))
		fromJson(std::move(*v), value.message);
}

void fromJson(json::Value&& json, WorkDoneProgressEnd& value)
{
	auto& obj = json.object();
	workDoneProgressEndFromJson(obj, value);
}

template<>
auto requiredProperties<WorkDoneProgressEnd>() -> const char**
{
	static const char* properties[] = {
		"kind",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<WorkDoneProgressEnd>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "end"},
		{nullptr, {}}
	};
	return properties;
}

static void setTraceParamsFromJson(json::Object& json, SetTraceParams& value)
{
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, SetTraceParams& value)
{
	auto& obj = json.object();
	setTraceParamsFromJson(obj, value);
}

template<>
auto requiredProperties<SetTraceParams>() -> const char**
{
	static const char* properties[] = {
		"value",
		nullptr
	};
	return properties;
}

static void logTraceParamsFromJson(json::Object& json, LogTraceParams& value)
{
	fromJson(std::move(json.get("message")), value.message);
	if(auto* const v = json.find("verbose"))
		fromJson(std::move(*v), value.verbose);
}

void fromJson(json::Value&& json, LogTraceParams& value)
{
	auto& obj = json.object();
	logTraceParamsFromJson(obj, value);
}

template<>
auto requiredProperties<LogTraceParams>() -> const char**
{
	static const char* properties[] = {
		"message",
		nullptr
	};
	return properties;
}

static void cancelParamsFromJson(json::Object& json, CancelParams& value)
{
	fromJson(std::move(json.get("id")), value.id);
}

void fromJson(json::Value&& json, CancelParams& value)
{
	auto& obj = json.object();
	cancelParamsFromJson(obj, value);
}

template<>
auto requiredProperties<CancelParams>() -> const char**
{
	static const char* properties[] = {
		"id",
		nullptr
	};
	return properties;
}

static void progressParamsFromJson(json::Object& json, ProgressParams& value)
{
	fromJson(std::move(json.get("token")), value.token);
	fromJson(std::move(json.get("value")), value.value);
}

void fromJson(json::Value&& json, ProgressParams& value)
{
	auto& obj = json.object();
	progressParamsFromJson(obj, value);
}

template<>
auto requiredProperties<ProgressParams>() -> const char**
{
	static const char* properties[] = {
		"token",
		"value",
		nullptr
	};
	return properties;
}

static void locationLinkFromJson(json::Object& json, LocationLink& value)
{
	fromJson(std::move(json.get("targetUri")), value.targetUri);
	fromJson(std::move(json.get("targetRange")), value.targetRange);
	fromJson(std::move(json.get("targetSelectionRange")), value.targetSelectionRange);
	if(auto* const v = json.find("originSelectionRange"))
		fromJson(std::move(*v), value.originSelectionRange);
}

void fromJson(json::Value&& json, LocationLink& value)
{
	auto& obj = json.object();
	locationLinkFromJson(obj, value);
}

template<>
auto requiredProperties<LocationLink>() -> const char**
{
	static const char* properties[] = {
		"targetUri",
		"targetRange",
		"targetSelectionRange",
		nullptr
	};
	return properties;
}

static void inlineValueTextFromJson(json::Object& json, InlineValueText& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("text")), value.text);
}

void fromJson(json::Value&& json, InlineValueText& value)
{
	auto& obj = json.object();
	inlineValueTextFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueText>() -> const char**
{
	static const char* properties[] = {
		"range",
		"text",
		nullptr
	};
	return properties;
}

static void inlineValueVariableLookupFromJson(json::Object& json, InlineValueVariableLookup& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("caseSensitiveLookup")), value.caseSensitiveLookup);
	if(auto* const v = json.find("variableName"))
		fromJson(std::move(*v), value.variableName);
}

void fromJson(json::Value&& json, InlineValueVariableLookup& value)
{
	auto& obj = json.object();
	inlineValueVariableLookupFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueVariableLookup>() -> const char**
{
	static const char* properties[] = {
		"range",
		"caseSensitiveLookup",
		nullptr
	};
	return properties;
}

static void inlineValueEvaluatableExpressionFromJson(json::Object& json, InlineValueEvaluatableExpression& value)
{
	fromJson(std::move(json.get("range")), value.range);
	if(auto* const v = json.find("expression"))
		fromJson(std::move(*v), value.expression);
}

void fromJson(json::Value&& json, InlineValueEvaluatableExpression& value)
{
	auto& obj = json.object();
	inlineValueEvaluatableExpressionFromJson(obj, value);
}

template<>
auto requiredProperties<InlineValueEvaluatableExpression>() -> const char**
{
	static const char* properties[] = {
		"range",
		nullptr
	};
	return properties;
}

static void relatedFullDocumentDiagnosticReportFromJson(json::Object& json, RelatedFullDocumentDiagnosticReport& value)
{
	fullDocumentDiagnosticReportFromJson(json, value);
	if(auto* const v = json.find("relatedDocuments"))
		fromJson(std::move(*v), value.relatedDocuments);
}

void fromJson(json::Value&& json, RelatedFullDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	relatedFullDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<RelatedFullDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"items",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<RelatedFullDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "full"},
		{nullptr, {}}
	};
	return properties;
}

static void relatedUnchangedDocumentDiagnosticReportFromJson(json::Object& json, RelatedUnchangedDocumentDiagnosticReport& value)
{
	unchangedDocumentDiagnosticReportFromJson(json, value);
	if(auto* const v = json.find("relatedDocuments"))
		fromJson(std::move(*v), value.relatedDocuments);
}

void fromJson(json::Value&& json, RelatedUnchangedDocumentDiagnosticReport& value)
{
	auto& obj = json.object();
	relatedUnchangedDocumentDiagnosticReportFromJson(obj, value);
}

template<>
auto requiredProperties<RelatedUnchangedDocumentDiagnosticReport>() -> const char**
{
	static const char* properties[] = {
		"kind",
		"resultId",
		nullptr
	};
	return properties;
}

template<>
auto literalProperties<RelatedUnchangedDocumentDiagnosticReport>() -> const std::pair<const char*, json::Value>*
{
	static const std::pair<const char*, json::Value> properties[] = {
		{"kind", "unchanged"},
		{nullptr, {}}
	};
	return properties;
}

static void documentDiagnosticReportPartialResultFromJson(json::Object& json, DocumentDiagnosticReportPartialResult& value)
{
	fromJson(std::move(json.get("relatedDocuments")), value.relatedDocuments);
}

void fromJson(json::Value&& json, DocumentDiagnosticReportPartialResult& value)
{
	auto& obj = json.object();
	documentDiagnosticReportPartialResultFromJson(obj, value);
}

template<>
auto requiredProperties<DocumentDiagnosticReportPartialResult>() -> const char**
{
	static const char* properties[] = {
		"relatedDocuments",
		nullptr
	};
	return properties;
}

static void prepareRenamePlaceholderFromJson(json::Object& json, PrepareRenamePlaceholder& value)
{
	fromJson(std::move(json.get("range")), value.range);
	fromJson(std::move(json.get("placeholder")), value.placeholder);
}

void fromJson(json::Value&& json, PrepareRenamePlaceholder& value)
{
	auto& obj = json.object();
	prepareRenamePlaceholderFromJson(obj, value);
}

template<>
auto requiredProperties<PrepareRenamePlaceholder>() -> const char**
{
	static const char* properties[] = {
		"range",
		"placeholder",
		nullptr
	};
	return properties;
}

static void prepareRenameDefaultBehaviorFromJson(json::Object& json, PrepareRenameDefaultBehavior& value)
{
	fromJson(std::move(json.get("defaultBehavior")), value.defaultBehavior);
}

void fromJson(json::Value&& json, PrepareRenameDefaultBehavior& value)
{
	auto& obj = json.object();
	prepareRenameDefaultBehaviorFromJson(obj, value);
}

template<>
auto requiredProperties<PrepareRenameDefaultBehavior>() -> const char**
{
	static const char* properties[] = {
		"defaultBehavior",
		nullptr
	};
	return properties;
}

void writeJson(const TextDocumentIdentifier& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const Position& value, json::ObjectWriter& objectWriter)
{
	writeJson("line", value.line, objectWriter);
	writeJson("character", value.character, objectWriter);
}

void writeJson(const TextDocumentPositionParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("position", value.position, objectWriter);
}

void writeJson(const WorkDoneProgressParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const PartialResultParams& value, json::ObjectWriter& objectWriter)
{
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const ImplementationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const Range& value, json::ObjectWriter& objectWriter)
{
	writeJson("start", value.start, objectWriter);
	writeJson("end", value.end, objectWriter);
}

void writeJson(const Location& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("range", value.range, objectWriter);
}

void writeJson(const WorkspaceFolder& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("name", value.name, objectWriter);
}

void writeJson(const RelativePattern& value, json::ObjectWriter& objectWriter)
{
	writeJson("baseUri", value.baseUri, objectWriter);
	writeJson("pattern", value.pattern, objectWriter);
}

void writeJson(const TextDocumentFilterLanguage& value, json::ObjectWriter& objectWriter)
{
	writeJson("language", value.language, objectWriter);
	if(value.scheme)
		writeJson("scheme", value.scheme, objectWriter);
	if(value.pattern)
		writeJson("pattern", value.pattern, objectWriter);
}

void writeJson(const TextDocumentFilterScheme& value, json::ObjectWriter& objectWriter)
{
	writeJson("scheme", value.scheme, objectWriter);
	if(value.language)
		writeJson("language", value.language, objectWriter);
	if(value.pattern)
		writeJson("pattern", value.pattern, objectWriter);
}

void writeJson(const TextDocumentFilterPattern& value, json::ObjectWriter& objectWriter)
{
	writeJson("pattern", value.pattern, objectWriter);
	if(value.language)
		writeJson("language", value.language, objectWriter);
	if(value.scheme)
		writeJson("scheme", value.scheme, objectWriter);
}

void writeJson(const NotebookDocumentFilterNotebookType& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookType", value.notebookType, objectWriter);
	if(value.scheme)
		writeJson("scheme", value.scheme, objectWriter);
	if(value.pattern)
		writeJson("pattern", value.pattern, objectWriter);
}

void writeJson(const NotebookDocumentFilterScheme& value, json::ObjectWriter& objectWriter)
{
	writeJson("scheme", value.scheme, objectWriter);
	if(value.notebookType)
		writeJson("notebookType", value.notebookType, objectWriter);
	if(value.pattern)
		writeJson("pattern", value.pattern, objectWriter);
}

void writeJson(const NotebookDocumentFilterPattern& value, json::ObjectWriter& objectWriter)
{
	writeJson("pattern", value.pattern, objectWriter);
	if(value.notebookType)
		writeJson("notebookType", value.notebookType, objectWriter);
	if(value.scheme)
		writeJson("scheme", value.scheme, objectWriter);
}

void writeJson(const NotebookCellTextDocumentFilter& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebook", value.notebook, objectWriter);
	if(value.language)
		writeJson("language", value.language, objectWriter);
}

void writeJson(const TextDocumentRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("documentSelector", value.documentSelector, objectWriter);
}

void writeJson(const WorkDoneProgressOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const ImplementationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const StaticRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const ImplementationRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const ImplementationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const TypeDefinitionParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const TypeDefinitionOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const TypeDefinitionRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const TypeDefinitionOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const WorkspaceFoldersChangeEvent& value, json::ObjectWriter& objectWriter)
{
	writeJson("added", value.added, objectWriter);
	writeJson("removed", value.removed, objectWriter);
}

void writeJson(const DidChangeWorkspaceFoldersParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("event", value.event, objectWriter);
}

void writeJson(const ConfigurationItem& value, json::ObjectWriter& objectWriter)
{
	if(value.scopeUri)
		writeJson("scopeUri", value.scopeUri, objectWriter);
	if(value.section)
		writeJson("section", value.section, objectWriter);
}

void writeJson(const ConfigurationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("items", value.items, objectWriter);
}

void writeJson(const DocumentColorParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const Color& value, json::ObjectWriter& objectWriter)
{
	writeJson("red", value.red, objectWriter);
	writeJson("green", value.green, objectWriter);
	writeJson("blue", value.blue, objectWriter);
	writeJson("alpha", value.alpha, objectWriter);
}

void writeJson(const ColorInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("color", value.color, objectWriter);
}

void writeJson(const DocumentColorOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const DocumentColorRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentColorOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const ColorPresentationParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("color", value.color, objectWriter);
	writeJson("range", value.range, objectWriter);
}

void writeJson(const TextEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("newText", value.newText, objectWriter);
}

void writeJson(const ColorPresentation& value, json::ObjectWriter& objectWriter)
{
	writeJson("label", value.label, objectWriter);
	if(value.textEdit)
		writeJson("textEdit", value.textEdit, objectWriter);
	if(value.additionalTextEdits)
		writeJson("additionalTextEdits", value.additionalTextEdits, objectWriter);
}

void writeJson(const FoldingRangeParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const FoldingRange& value, json::ObjectWriter& objectWriter)
{
	writeJson("startLine", value.startLine, objectWriter);
	writeJson("endLine", value.endLine, objectWriter);
	if(value.startCharacter)
		writeJson("startCharacter", value.startCharacter, objectWriter);
	if(value.endCharacter)
		writeJson("endCharacter", value.endCharacter, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
	if(value.collapsedText)
		writeJson("collapsedText", value.collapsedText, objectWriter);
}

void writeJson(const FoldingRangeOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const FoldingRangeRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const FoldingRangeOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const DeclarationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const DeclarationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const DeclarationRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const DeclarationOptions&>(value), objectWriter);
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const SelectionRangeParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("positions", value.positions, objectWriter);
}

void writeJson(const SelectionRange& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	if(value.parent)
		writeJson("parent", value.parent, objectWriter);
}

void writeJson(const SelectionRangeOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const SelectionRangeRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const SelectionRangeOptions&>(value), objectWriter);
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const WorkDoneProgressCreateParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("token", value.token, objectWriter);
}

void writeJson(const WorkDoneProgressCancelParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("token", value.token, objectWriter);
}

void writeJson(const CallHierarchyPrepareParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const CallHierarchyItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	writeJson("kind", value.kind, objectWriter);
	writeJson("uri", value.uri, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("selectionRange", value.selectionRange, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.detail)
		writeJson("detail", value.detail, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const CallHierarchyOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const CallHierarchyRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const CallHierarchyOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const CallHierarchyIncomingCallsParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("item", value.item, objectWriter);
}

void writeJson(const CallHierarchyIncomingCall& value, json::ObjectWriter& objectWriter)
{
	writeJson("from", value.from, objectWriter);
	writeJson("fromRanges", value.fromRanges, objectWriter);
}

void writeJson(const CallHierarchyOutgoingCallsParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("item", value.item, objectWriter);
}

void writeJson(const CallHierarchyOutgoingCall& value, json::ObjectWriter& objectWriter)
{
	writeJson("to", value.to, objectWriter);
	writeJson("fromRanges", value.fromRanges, objectWriter);
}

void writeJson(const SemanticTokensParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const SemanticTokens& value, json::ObjectWriter& objectWriter)
{
	writeJson("data", value.data, objectWriter);
	if(value.resultId)
		writeJson("resultId", value.resultId, objectWriter);
}

void writeJson(const SemanticTokensPartialResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("data", value.data, objectWriter);
}

void writeJson(const SemanticTokensLegend& value, json::ObjectWriter& objectWriter)
{
	writeJson("tokenTypes", value.tokenTypes, objectWriter);
	writeJson("tokenModifiers", value.tokenModifiers, objectWriter);
}

void writeJson(const SemanticTokensOptionsRange& value, json::ObjectWriter& objectWriter)
{
}

void writeJson(const SemanticTokensFullDelta& value, json::ObjectWriter& objectWriter)
{
	if(value.delta)
		writeJson("delta", value.delta, objectWriter);
}

void writeJson(const SemanticTokensOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	writeJson("legend", value.legend, objectWriter);
	if(value.range)
		writeJson("range", value.range, objectWriter);
	if(value.full)
		writeJson("full", value.full, objectWriter);
}

void writeJson(const SemanticTokensRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const SemanticTokensOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const SemanticTokensDeltaParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("previousResultId", value.previousResultId, objectWriter);
}

void writeJson(const SemanticTokensEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson("start", value.start, objectWriter);
	writeJson("deleteCount", value.deleteCount, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const SemanticTokensDelta& value, json::ObjectWriter& objectWriter)
{
	writeJson("edits", value.edits, objectWriter);
	if(value.resultId)
		writeJson("resultId", value.resultId, objectWriter);
}

void writeJson(const SemanticTokensDeltaPartialResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("edits", value.edits, objectWriter);
}

void writeJson(const SemanticTokensRangeParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("range", value.range, objectWriter);
}

void writeJson(const ShowDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	if(value.external)
		writeJson("external", value.external, objectWriter);
	if(value.takeFocus)
		writeJson("takeFocus", value.takeFocus, objectWriter);
	if(value.selection)
		writeJson("selection", value.selection, objectWriter);
}

void writeJson(const ShowDocumentResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("success", value.success, objectWriter);
}

void writeJson(const LinkedEditingRangeParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const LinkedEditingRanges& value, json::ObjectWriter& objectWriter)
{
	writeJson("ranges", value.ranges, objectWriter);
	if(value.wordPattern)
		writeJson("wordPattern", value.wordPattern, objectWriter);
}

void writeJson(const LinkedEditingRangeOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const LinkedEditingRangeRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const LinkedEditingRangeOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const FileCreate& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const CreateFilesParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("files", value.files, objectWriter);
}

void writeJson(const OptionalVersionedTextDocumentIdentifier& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentIdentifier&>(value), objectWriter);
	writeJson("version", value.version, objectWriter);
}

void writeJson(const AnnotatedTextEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextEdit&>(value), objectWriter);
	writeJson("annotationId", value.annotationId, objectWriter);
}

void writeJson(const StringValue& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("value", value.value, objectWriter);
}

void writeJson(const SnippetTextEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("snippet", value.snippet, objectWriter);
	if(value.annotationId)
		writeJson("annotationId", value.annotationId, objectWriter);
}

void writeJson(const TextDocumentEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("edits", value.edits, objectWriter);
}

void writeJson(const ResourceOperation& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	if(value.annotationId)
		writeJson("annotationId", value.annotationId, objectWriter);
}

void writeJson(const CreateFileOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.overwrite)
		writeJson("overwrite", value.overwrite, objectWriter);
	if(value.ignoreIfExists)
		writeJson("ignoreIfExists", value.ignoreIfExists, objectWriter);
}

void writeJson(const CreateFile& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const ResourceOperation&>(value), objectWriter);
	writeJson("uri", value.uri, objectWriter);
	if(value.options)
		writeJson("options", value.options, objectWriter);
}

void writeJson(const RenameFileOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.overwrite)
		writeJson("overwrite", value.overwrite, objectWriter);
	if(value.ignoreIfExists)
		writeJson("ignoreIfExists", value.ignoreIfExists, objectWriter);
}

void writeJson(const RenameFile& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const ResourceOperation&>(value), objectWriter);
	writeJson("oldUri", value.oldUri, objectWriter);
	writeJson("newUri", value.newUri, objectWriter);
	if(value.options)
		writeJson("options", value.options, objectWriter);
}

void writeJson(const DeleteFileOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.recursive)
		writeJson("recursive", value.recursive, objectWriter);
	if(value.ignoreIfNotExists)
		writeJson("ignoreIfNotExists", value.ignoreIfNotExists, objectWriter);
}

void writeJson(const DeleteFile& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const ResourceOperation&>(value), objectWriter);
	writeJson("uri", value.uri, objectWriter);
	if(value.options)
		writeJson("options", value.options, objectWriter);
}

void writeJson(const ChangeAnnotation& value, json::ObjectWriter& objectWriter)
{
	writeJson("label", value.label, objectWriter);
	if(value.needsConfirmation)
		writeJson("needsConfirmation", value.needsConfirmation, objectWriter);
	if(value.description)
		writeJson("description", value.description, objectWriter);
}

void writeJson(const WorkspaceEdit& value, json::ObjectWriter& objectWriter)
{
	if(value.changes)
		writeJson("changes", value.changes, objectWriter);
	if(value.documentChanges)
		writeJson("documentChanges", value.documentChanges, objectWriter);
	if(value.changeAnnotations)
		writeJson("changeAnnotations", value.changeAnnotations, objectWriter);
}

void writeJson(const FileOperationPatternOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.ignoreCase)
		writeJson("ignoreCase", value.ignoreCase, objectWriter);
}

void writeJson(const FileOperationPattern& value, json::ObjectWriter& objectWriter)
{
	writeJson("glob", value.glob, objectWriter);
	if(value.matches)
		writeJson("matches", value.matches, objectWriter);
	if(value.options)
		writeJson("options", value.options, objectWriter);
}

void writeJson(const FileOperationFilter& value, json::ObjectWriter& objectWriter)
{
	writeJson("pattern", value.pattern, objectWriter);
	if(value.scheme)
		writeJson("scheme", value.scheme, objectWriter);
}

void writeJson(const FileOperationRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("filters", value.filters, objectWriter);
}

void writeJson(const FileRename& value, json::ObjectWriter& objectWriter)
{
	writeJson("oldUri", value.oldUri, objectWriter);
	writeJson("newUri", value.newUri, objectWriter);
}

void writeJson(const RenameFilesParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("files", value.files, objectWriter);
}

void writeJson(const FileDelete& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const DeleteFilesParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("files", value.files, objectWriter);
}

void writeJson(const MonikerParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const Moniker& value, json::ObjectWriter& objectWriter)
{
	writeJson("scheme", value.scheme, objectWriter);
	writeJson("identifier", value.identifier, objectWriter);
	writeJson("unique", value.unique, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
}

void writeJson(const MonikerOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const MonikerRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const MonikerOptions&>(value), objectWriter);
}

void writeJson(const TypeHierarchyPrepareParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const TypeHierarchyItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	writeJson("kind", value.kind, objectWriter);
	writeJson("uri", value.uri, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("selectionRange", value.selectionRange, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.detail)
		writeJson("detail", value.detail, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const TypeHierarchyOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const TypeHierarchyRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const TypeHierarchyOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const TypeHierarchySupertypesParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("item", value.item, objectWriter);
}

void writeJson(const TypeHierarchySubtypesParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("item", value.item, objectWriter);
}

void writeJson(const InlineValueContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("frameId", value.frameId, objectWriter);
	writeJson("stoppedLocation", value.stoppedLocation, objectWriter);
}

void writeJson(const InlineValueParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("context", value.context, objectWriter);
}

void writeJson(const InlineValueOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const InlineValueRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const InlineValueOptions&>(value), objectWriter);
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const InlayHintParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("range", value.range, objectWriter);
}

void writeJson(const MarkupContent& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("value", value.value, objectWriter);
}

void writeJson(const Command& value, json::ObjectWriter& objectWriter)
{
	writeJson("title", value.title, objectWriter);
	writeJson("command", value.command, objectWriter);
	if(value.tooltip)
		writeJson("tooltip", value.tooltip, objectWriter);
	if(value.arguments)
		writeJson("arguments", value.arguments, objectWriter);
}

void writeJson(const InlayHintLabelPart& value, json::ObjectWriter& objectWriter)
{
	writeJson("value", value.value, objectWriter);
	if(value.tooltip)
		writeJson("tooltip", value.tooltip, objectWriter);
	if(value.location)
		writeJson("location", value.location, objectWriter);
	if(value.command)
		writeJson("command", value.command, objectWriter);
}

void writeJson(const InlayHint& value, json::ObjectWriter& objectWriter)
{
	writeJson("position", value.position, objectWriter);
	writeJson("label", value.label, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
	if(value.textEdits)
		writeJson("textEdits", value.textEdits, objectWriter);
	if(value.tooltip)
		writeJson("tooltip", value.tooltip, objectWriter);
	if(value.paddingLeft)
		writeJson("paddingLeft", value.paddingLeft, objectWriter);
	if(value.paddingRight)
		writeJson("paddingRight", value.paddingRight, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const InlayHintOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
}

void writeJson(const InlayHintRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const InlayHintOptions&>(value), objectWriter);
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const DocumentDiagnosticParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	if(value.identifier)
		writeJson("identifier", value.identifier, objectWriter);
	if(value.previousResultId)
		writeJson("previousResultId", value.previousResultId, objectWriter);
}

void writeJson(const DiagnosticServerCancellationData& value, json::ObjectWriter& objectWriter)
{
	writeJson("retriggerRequest", value.retriggerRequest, objectWriter);
}

void writeJson(const DiagnosticOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	writeJson("interFileDependencies", value.interFileDependencies, objectWriter);
	writeJson("workspaceDiagnostics", value.workspaceDiagnostics, objectWriter);
	if(value.identifier)
		writeJson("identifier", value.identifier, objectWriter);
}

void writeJson(const DiagnosticRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DiagnosticOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const PreviousResultId& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("value", value.value, objectWriter);
}

void writeJson(const WorkspaceDiagnosticParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("previousResultIds", value.previousResultIds, objectWriter);
	if(value.identifier)
		writeJson("identifier", value.identifier, objectWriter);
}

void writeJson(const CodeDescription& value, json::ObjectWriter& objectWriter)
{
	writeJson("href", value.href, objectWriter);
}

void writeJson(const DiagnosticRelatedInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson("location", value.location, objectWriter);
	writeJson("message", value.message, objectWriter);
}

void writeJson(const Diagnostic& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("message", value.message, objectWriter);
	if(value.severity)
		writeJson("severity", value.severity, objectWriter);
	if(value.code)
		writeJson("code", value.code, objectWriter);
	if(value.codeDescription)
		writeJson("codeDescription", value.codeDescription, objectWriter);
	if(value.source)
		writeJson("source", value.source, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.relatedInformation)
		writeJson("relatedInformation", value.relatedInformation, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const FullDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("items", value.items, objectWriter);
	if(value.resultId)
		writeJson("resultId", value.resultId, objectWriter);
}

void writeJson(const WorkspaceFullDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const FullDocumentDiagnosticReport&>(value), objectWriter);
	writeJson("uri", value.uri, objectWriter);
	writeJson("version", value.version, objectWriter);
}

void writeJson(const UnchangedDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("resultId", value.resultId, objectWriter);
}

void writeJson(const WorkspaceUnchangedDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const UnchangedDocumentDiagnosticReport&>(value), objectWriter);
	writeJson("uri", value.uri, objectWriter);
	writeJson("version", value.version, objectWriter);
}

void writeJson(const WorkspaceDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson("items", value.items, objectWriter);
}

void writeJson(const WorkspaceDiagnosticReportPartialResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("items", value.items, objectWriter);
}

void writeJson(const ExecutionSummary& value, json::ObjectWriter& objectWriter)
{
	writeJson("executionOrder", value.executionOrder, objectWriter);
	if(value.success)
		writeJson("success", value.success, objectWriter);
}

void writeJson(const NotebookCell& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("document", value.document, objectWriter);
	if(value.metadata)
		writeJson("metadata", value.metadata, objectWriter);
	if(value.executionSummary)
		writeJson("executionSummary", value.executionSummary, objectWriter);
}

void writeJson(const NotebookDocument& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("notebookType", value.notebookType, objectWriter);
	writeJson("version", value.version, objectWriter);
	writeJson("cells", value.cells, objectWriter);
	if(value.metadata)
		writeJson("metadata", value.metadata, objectWriter);
}

void writeJson(const TextDocumentItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("languageId", value.languageId, objectWriter);
	writeJson("version", value.version, objectWriter);
	writeJson("text", value.text, objectWriter);
}

void writeJson(const DidOpenNotebookDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookDocument", value.notebookDocument, objectWriter);
	writeJson("cellTextDocuments", value.cellTextDocuments, objectWriter);
}

void writeJson(const NotebookCellLanguage& value, json::ObjectWriter& objectWriter)
{
	writeJson("language", value.language, objectWriter);
}

void writeJson(const NotebookDocumentFilterWithNotebook& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebook", value.notebook, objectWriter);
	if(value.cells)
		writeJson("cells", value.cells, objectWriter);
}

void writeJson(const NotebookDocumentFilterWithCells& value, json::ObjectWriter& objectWriter)
{
	writeJson("cells", value.cells, objectWriter);
	if(value.notebook)
		writeJson("notebook", value.notebook, objectWriter);
}

void writeJson(const NotebookDocumentSyncOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookSelector", value.notebookSelector, objectWriter);
	if(value.save)
		writeJson("save", value.save, objectWriter);
}

void writeJson(const NotebookDocumentSyncRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const NotebookDocumentSyncOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const VersionedNotebookDocumentIdentifier& value, json::ObjectWriter& objectWriter)
{
	writeJson("version", value.version, objectWriter);
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const NotebookCellArrayChange& value, json::ObjectWriter& objectWriter)
{
	writeJson("start", value.start, objectWriter);
	writeJson("deleteCount", value.deleteCount, objectWriter);
	if(value.cells)
		writeJson("cells", value.cells, objectWriter);
}

void writeJson(const NotebookDocumentCellChangeStructure& value, json::ObjectWriter& objectWriter)
{
	writeJson("array", value.array, objectWriter);
	if(value.didOpen)
		writeJson("didOpen", value.didOpen, objectWriter);
	if(value.didClose)
		writeJson("didClose", value.didClose, objectWriter);
}

void writeJson(const VersionedTextDocumentIdentifier& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentIdentifier&>(value), objectWriter);
	writeJson("version", value.version, objectWriter);
}

void writeJson(const TextDocumentContentChangePartial& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("text", value.text, objectWriter);
	if(value.rangeLength)
		writeJson("rangeLength", value.rangeLength, objectWriter);
}

void writeJson(const TextDocumentContentChangeWholeDocument& value, json::ObjectWriter& objectWriter)
{
	writeJson("text", value.text, objectWriter);
}

void writeJson(const NotebookDocumentCellContentChanges& value, json::ObjectWriter& objectWriter)
{
	writeJson("document", value.document, objectWriter);
	writeJson("changes", value.changes, objectWriter);
}

void writeJson(const NotebookDocumentCellChanges& value, json::ObjectWriter& objectWriter)
{
	if(value.structure)
		writeJson("structure", value.structure, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
	if(value.textContent)
		writeJson("textContent", value.textContent, objectWriter);
}

void writeJson(const NotebookDocumentChangeEvent& value, json::ObjectWriter& objectWriter)
{
	if(value.metadata)
		writeJson("metadata", value.metadata, objectWriter);
	if(value.cells)
		writeJson("cells", value.cells, objectWriter);
}

void writeJson(const DidChangeNotebookDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookDocument", value.notebookDocument, objectWriter);
	writeJson("change", value.change, objectWriter);
}

void writeJson(const NotebookDocumentIdentifier& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const DidSaveNotebookDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookDocument", value.notebookDocument, objectWriter);
}

void writeJson(const DidCloseNotebookDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("notebookDocument", value.notebookDocument, objectWriter);
	writeJson("cellTextDocuments", value.cellTextDocuments, objectWriter);
}

void writeJson(const SelectedCompletionInfo& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("text", value.text, objectWriter);
}

void writeJson(const InlineCompletionContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("triggerKind", value.triggerKind, objectWriter);
	if(value.selectedCompletionInfo)
		writeJson("selectedCompletionInfo", value.selectedCompletionInfo, objectWriter);
}

void writeJson(const InlineCompletionParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("context", value.context, objectWriter);
}

void writeJson(const InlineCompletionItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("insertText", value.insertText, objectWriter);
	if(value.filterText)
		writeJson("filterText", value.filterText, objectWriter);
	if(value.range)
		writeJson("range", value.range, objectWriter);
	if(value.command)
		writeJson("command", value.command, objectWriter);
}

void writeJson(const InlineCompletionList& value, json::ObjectWriter& objectWriter)
{
	writeJson("items", value.items, objectWriter);
}

void writeJson(const InlineCompletionOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const InlineCompletionRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const InlineCompletionOptions&>(value), objectWriter);
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const TextDocumentContentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const TextDocumentContentResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("text", value.text, objectWriter);
}

void writeJson(const TextDocumentContentOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("schemes", value.schemes, objectWriter);
}

void writeJson(const TextDocumentContentRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentContentOptions&>(value), objectWriter);
	if(value.id)
		writeJson("id", value.id, objectWriter);
}

void writeJson(const TextDocumentContentRefreshParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const Registration& value, json::ObjectWriter& objectWriter)
{
	writeJson("id", value.id, objectWriter);
	writeJson("method", value.method, objectWriter);
	if(value.registerOptions)
		writeJson("registerOptions", value.registerOptions, objectWriter);
}

void writeJson(const RegistrationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("registrations", value.registrations, objectWriter);
}

void writeJson(const Unregistration& value, json::ObjectWriter& objectWriter)
{
	writeJson("id", value.id, objectWriter);
	writeJson("method", value.method, objectWriter);
}

void writeJson(const UnregistrationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("unregisterations", value.unregisterations, objectWriter);
}

void writeJson(const ChangeAnnotationsSupportOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.groupsOnLabel)
		writeJson("groupsOnLabel", value.groupsOnLabel, objectWriter);
}

void writeJson(const WorkspaceEditClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.documentChanges)
		writeJson("documentChanges", value.documentChanges, objectWriter);
	if(value.resourceOperations)
		writeJson("resourceOperations", value.resourceOperations, objectWriter);
	if(value.failureHandling)
		writeJson("failureHandling", value.failureHandling, objectWriter);
	if(value.normalizesLineEndings)
		writeJson("normalizesLineEndings", value.normalizesLineEndings, objectWriter);
	if(value.changeAnnotationSupport)
		writeJson("changeAnnotationSupport", value.changeAnnotationSupport, objectWriter);
	if(value.metadataSupport)
		writeJson("metadataSupport", value.metadataSupport, objectWriter);
	if(value.snippetEditSupport)
		writeJson("snippetEditSupport", value.snippetEditSupport, objectWriter);
}

void writeJson(const DidChangeConfigurationClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const DidChangeWatchedFilesClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.relativePatternSupport)
		writeJson("relativePatternSupport", value.relativePatternSupport, objectWriter);
}

void writeJson(const ClientSymbolKindOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.valueSet)
		writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientSymbolTagOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientSymbolResolveOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("properties", value.properties, objectWriter);
}

void writeJson(const WorkspaceSymbolClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.symbolKind)
		writeJson("symbolKind", value.symbolKind, objectWriter);
	if(value.tagSupport)
		writeJson("tagSupport", value.tagSupport, objectWriter);
	if(value.resolveSupport)
		writeJson("resolveSupport", value.resolveSupport, objectWriter);
}

void writeJson(const ExecuteCommandClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const SemanticTokensWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const CodeLensWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const FileOperationClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.didCreate)
		writeJson("didCreate", value.didCreate, objectWriter);
	if(value.willCreate)
		writeJson("willCreate", value.willCreate, objectWriter);
	if(value.didRename)
		writeJson("didRename", value.didRename, objectWriter);
	if(value.willRename)
		writeJson("willRename", value.willRename, objectWriter);
	if(value.didDelete)
		writeJson("didDelete", value.didDelete, objectWriter);
	if(value.willDelete)
		writeJson("willDelete", value.willDelete, objectWriter);
}

void writeJson(const InlineValueWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const InlayHintWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const DiagnosticWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const FoldingRangeWorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.refreshSupport)
		writeJson("refreshSupport", value.refreshSupport, objectWriter);
}

void writeJson(const TextDocumentContentClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const WorkspaceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.applyEdit)
		writeJson("applyEdit", value.applyEdit, objectWriter);
	if(value.workspaceEdit)
		writeJson("workspaceEdit", value.workspaceEdit, objectWriter);
	if(value.didChangeConfiguration)
		writeJson("didChangeConfiguration", value.didChangeConfiguration, objectWriter);
	if(value.didChangeWatchedFiles)
		writeJson("didChangeWatchedFiles", value.didChangeWatchedFiles, objectWriter);
	if(value.symbol)
		writeJson("symbol", value.symbol, objectWriter);
	if(value.executeCommand)
		writeJson("executeCommand", value.executeCommand, objectWriter);
	if(value.workspaceFolders)
		writeJson("workspaceFolders", value.workspaceFolders, objectWriter);
	if(value.configuration)
		writeJson("configuration", value.configuration, objectWriter);
	if(value.semanticTokens)
		writeJson("semanticTokens", value.semanticTokens, objectWriter);
	if(value.codeLens)
		writeJson("codeLens", value.codeLens, objectWriter);
	if(value.fileOperations)
		writeJson("fileOperations", value.fileOperations, objectWriter);
	if(value.inlineValue)
		writeJson("inlineValue", value.inlineValue, objectWriter);
	if(value.inlayHint)
		writeJson("inlayHint", value.inlayHint, objectWriter);
	if(value.diagnostics)
		writeJson("diagnostics", value.diagnostics, objectWriter);
	if(value.foldingRange)
		writeJson("foldingRange", value.foldingRange, objectWriter);
	if(value.textDocumentContent)
		writeJson("textDocumentContent", value.textDocumentContent, objectWriter);
}

void writeJson(const TextDocumentSyncClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.willSave)
		writeJson("willSave", value.willSave, objectWriter);
	if(value.willSaveWaitUntil)
		writeJson("willSaveWaitUntil", value.willSaveWaitUntil, objectWriter);
	if(value.didSave)
		writeJson("didSave", value.didSave, objectWriter);
}

void writeJson(const TextDocumentFilterClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.relativePatternSupport)
		writeJson("relativePatternSupport", value.relativePatternSupport, objectWriter);
}

void writeJson(const CompletionItemTagOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientCompletionItemResolveOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("properties", value.properties, objectWriter);
}

void writeJson(const ClientCompletionItemInsertTextModeOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientCompletionItemOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.snippetSupport)
		writeJson("snippetSupport", value.snippetSupport, objectWriter);
	if(value.commitCharactersSupport)
		writeJson("commitCharactersSupport", value.commitCharactersSupport, objectWriter);
	if(value.documentationFormat)
		writeJson("documentationFormat", value.documentationFormat, objectWriter);
	if(value.deprecatedSupport)
		writeJson("deprecatedSupport", value.deprecatedSupport, objectWriter);
	if(value.preselectSupport)
		writeJson("preselectSupport", value.preselectSupport, objectWriter);
	if(value.tagSupport)
		writeJson("tagSupport", value.tagSupport, objectWriter);
	if(value.insertReplaceSupport)
		writeJson("insertReplaceSupport", value.insertReplaceSupport, objectWriter);
	if(value.resolveSupport)
		writeJson("resolveSupport", value.resolveSupport, objectWriter);
	if(value.insertTextModeSupport)
		writeJson("insertTextModeSupport", value.insertTextModeSupport, objectWriter);
	if(value.labelDetailsSupport)
		writeJson("labelDetailsSupport", value.labelDetailsSupport, objectWriter);
}

void writeJson(const ClientCompletionItemOptionsKind& value, json::ObjectWriter& objectWriter)
{
	if(value.valueSet)
		writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const CompletionListCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.itemDefaults)
		writeJson("itemDefaults", value.itemDefaults, objectWriter);
	if(value.applyKindSupport)
		writeJson("applyKindSupport", value.applyKindSupport, objectWriter);
}

void writeJson(const CompletionClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.completionItem)
		writeJson("completionItem", value.completionItem, objectWriter);
	if(value.completionItemKind)
		writeJson("completionItemKind", value.completionItemKind, objectWriter);
	if(value.insertTextMode)
		writeJson("insertTextMode", value.insertTextMode, objectWriter);
	if(value.contextSupport)
		writeJson("contextSupport", value.contextSupport, objectWriter);
	if(value.completionList)
		writeJson("completionList", value.completionList, objectWriter);
}

void writeJson(const HoverClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.contentFormat)
		writeJson("contentFormat", value.contentFormat, objectWriter);
}

void writeJson(const ClientSignatureParameterInformationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.labelOffsetSupport)
		writeJson("labelOffsetSupport", value.labelOffsetSupport, objectWriter);
}

void writeJson(const ClientSignatureInformationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.documentationFormat)
		writeJson("documentationFormat", value.documentationFormat, objectWriter);
	if(value.parameterInformation)
		writeJson("parameterInformation", value.parameterInformation, objectWriter);
	if(value.activeParameterSupport)
		writeJson("activeParameterSupport", value.activeParameterSupport, objectWriter);
	if(value.noActiveParameterSupport)
		writeJson("noActiveParameterSupport", value.noActiveParameterSupport, objectWriter);
}

void writeJson(const SignatureHelpClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.signatureInformation)
		writeJson("signatureInformation", value.signatureInformation, objectWriter);
	if(value.contextSupport)
		writeJson("contextSupport", value.contextSupport, objectWriter);
}

void writeJson(const DeclarationClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.linkSupport)
		writeJson("linkSupport", value.linkSupport, objectWriter);
}

void writeJson(const DefinitionClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.linkSupport)
		writeJson("linkSupport", value.linkSupport, objectWriter);
}

void writeJson(const TypeDefinitionClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.linkSupport)
		writeJson("linkSupport", value.linkSupport, objectWriter);
}

void writeJson(const ImplementationClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.linkSupport)
		writeJson("linkSupport", value.linkSupport, objectWriter);
}

void writeJson(const ReferenceClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const DocumentHighlightClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const DocumentSymbolClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.symbolKind)
		writeJson("symbolKind", value.symbolKind, objectWriter);
	if(value.hierarchicalDocumentSymbolSupport)
		writeJson("hierarchicalDocumentSymbolSupport", value.hierarchicalDocumentSymbolSupport, objectWriter);
	if(value.tagSupport)
		writeJson("tagSupport", value.tagSupport, objectWriter);
	if(value.labelSupport)
		writeJson("labelSupport", value.labelSupport, objectWriter);
}

void writeJson(const ClientCodeActionKindOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientCodeActionLiteralOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("codeActionKind", value.codeActionKind, objectWriter);
}

void writeJson(const ClientCodeActionResolveOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("properties", value.properties, objectWriter);
}

void writeJson(const CodeActionTagOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const CodeActionClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.codeActionLiteralSupport)
		writeJson("codeActionLiteralSupport", value.codeActionLiteralSupport, objectWriter);
	if(value.isPreferredSupport)
		writeJson("isPreferredSupport", value.isPreferredSupport, objectWriter);
	if(value.disabledSupport)
		writeJson("disabledSupport", value.disabledSupport, objectWriter);
	if(value.dataSupport)
		writeJson("dataSupport", value.dataSupport, objectWriter);
	if(value.resolveSupport)
		writeJson("resolveSupport", value.resolveSupport, objectWriter);
	if(value.honorsChangeAnnotations)
		writeJson("honorsChangeAnnotations", value.honorsChangeAnnotations, objectWriter);
	if(value.documentationSupport)
		writeJson("documentationSupport", value.documentationSupport, objectWriter);
	if(value.tagSupport)
		writeJson("tagSupport", value.tagSupport, objectWriter);
}

void writeJson(const ClientCodeLensResolveOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("properties", value.properties, objectWriter);
}

void writeJson(const CodeLensClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.resolveSupport)
		writeJson("resolveSupport", value.resolveSupport, objectWriter);
}

void writeJson(const DocumentLinkClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.tooltipSupport)
		writeJson("tooltipSupport", value.tooltipSupport, objectWriter);
}

void writeJson(const DocumentColorClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const DocumentFormattingClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const DocumentRangeFormattingClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.rangesSupport)
		writeJson("rangesSupport", value.rangesSupport, objectWriter);
}

void writeJson(const DocumentOnTypeFormattingClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const RenameClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.prepareSupport)
		writeJson("prepareSupport", value.prepareSupport, objectWriter);
	if(value.prepareSupportDefaultBehavior)
		writeJson("prepareSupportDefaultBehavior", value.prepareSupportDefaultBehavior, objectWriter);
	if(value.honorsChangeAnnotations)
		writeJson("honorsChangeAnnotations", value.honorsChangeAnnotations, objectWriter);
}

void writeJson(const ClientFoldingRangeKindOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.valueSet)
		writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const ClientFoldingRangeOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.collapsedText)
		writeJson("collapsedText", value.collapsedText, objectWriter);
}

void writeJson(const FoldingRangeClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.rangeLimit)
		writeJson("rangeLimit", value.rangeLimit, objectWriter);
	if(value.lineFoldingOnly)
		writeJson("lineFoldingOnly", value.lineFoldingOnly, objectWriter);
	if(value.foldingRangeKind)
		writeJson("foldingRangeKind", value.foldingRangeKind, objectWriter);
	if(value.foldingRange)
		writeJson("foldingRange", value.foldingRange, objectWriter);
}

void writeJson(const SelectionRangeClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const ClientDiagnosticsTagOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("valueSet", value.valueSet, objectWriter);
}

void writeJson(const DiagnosticsCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.relatedInformation)
		writeJson("relatedInformation", value.relatedInformation, objectWriter);
	if(value.tagSupport)
		writeJson("tagSupport", value.tagSupport, objectWriter);
	if(value.codeDescriptionSupport)
		writeJson("codeDescriptionSupport", value.codeDescriptionSupport, objectWriter);
	if(value.dataSupport)
		writeJson("dataSupport", value.dataSupport, objectWriter);
}

void writeJson(const PublishDiagnosticsClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const DiagnosticsCapabilities&>(value), objectWriter);
	if(value.versionSupport)
		writeJson("versionSupport", value.versionSupport, objectWriter);
}

void writeJson(const CallHierarchyClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const ClientSemanticTokensRequestOptionsRange& value, json::ObjectWriter& objectWriter)
{
}

void writeJson(const ClientSemanticTokensRequestFullDelta& value, json::ObjectWriter& objectWriter)
{
	if(value.delta)
		writeJson("delta", value.delta, objectWriter);
}

void writeJson(const ClientSemanticTokensRequestOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.range)
		writeJson("range", value.range, objectWriter);
	if(value.full)
		writeJson("full", value.full, objectWriter);
}

void writeJson(const SemanticTokensClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson("requests", value.requests, objectWriter);
	writeJson("tokenTypes", value.tokenTypes, objectWriter);
	writeJson("tokenModifiers", value.tokenModifiers, objectWriter);
	writeJson("formats", value.formats, objectWriter);
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.overlappingTokenSupport)
		writeJson("overlappingTokenSupport", value.overlappingTokenSupport, objectWriter);
	if(value.multilineTokenSupport)
		writeJson("multilineTokenSupport", value.multilineTokenSupport, objectWriter);
	if(value.serverCancelSupport)
		writeJson("serverCancelSupport", value.serverCancelSupport, objectWriter);
	if(value.augmentsSyntaxTokens)
		writeJson("augmentsSyntaxTokens", value.augmentsSyntaxTokens, objectWriter);
}

void writeJson(const LinkedEditingRangeClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const MonikerClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const TypeHierarchyClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const InlineValueClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const ClientInlayHintResolveOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("properties", value.properties, objectWriter);
}

void writeJson(const InlayHintClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.resolveSupport)
		writeJson("resolveSupport", value.resolveSupport, objectWriter);
}

void writeJson(const DiagnosticClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const DiagnosticsCapabilities&>(value), objectWriter);
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.relatedDocumentSupport)
		writeJson("relatedDocumentSupport", value.relatedDocumentSupport, objectWriter);
	if(value.markupMessageSupport)
		writeJson("markupMessageSupport", value.markupMessageSupport, objectWriter);
}

void writeJson(const InlineCompletionClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
}

void writeJson(const TextDocumentClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.synchronization)
		writeJson("synchronization", value.synchronization, objectWriter);
	if(value.filters)
		writeJson("filters", value.filters, objectWriter);
	if(value.completion)
		writeJson("completion", value.completion, objectWriter);
	if(value.hover)
		writeJson("hover", value.hover, objectWriter);
	if(value.signatureHelp)
		writeJson("signatureHelp", value.signatureHelp, objectWriter);
	if(value.declaration)
		writeJson("declaration", value.declaration, objectWriter);
	if(value.definition)
		writeJson("definition", value.definition, objectWriter);
	if(value.typeDefinition)
		writeJson("typeDefinition", value.typeDefinition, objectWriter);
	if(value.implementation)
		writeJson("implementation", value.implementation, objectWriter);
	if(value.references)
		writeJson("references", value.references, objectWriter);
	if(value.documentHighlight)
		writeJson("documentHighlight", value.documentHighlight, objectWriter);
	if(value.documentSymbol)
		writeJson("documentSymbol", value.documentSymbol, objectWriter);
	if(value.codeAction)
		writeJson("codeAction", value.codeAction, objectWriter);
	if(value.codeLens)
		writeJson("codeLens", value.codeLens, objectWriter);
	if(value.documentLink)
		writeJson("documentLink", value.documentLink, objectWriter);
	if(value.colorProvider)
		writeJson("colorProvider", value.colorProvider, objectWriter);
	if(value.formatting)
		writeJson("formatting", value.formatting, objectWriter);
	if(value.rangeFormatting)
		writeJson("rangeFormatting", value.rangeFormatting, objectWriter);
	if(value.onTypeFormatting)
		writeJson("onTypeFormatting", value.onTypeFormatting, objectWriter);
	if(value.rename)
		writeJson("rename", value.rename, objectWriter);
	if(value.foldingRange)
		writeJson("foldingRange", value.foldingRange, objectWriter);
	if(value.selectionRange)
		writeJson("selectionRange", value.selectionRange, objectWriter);
	if(value.publishDiagnostics)
		writeJson("publishDiagnostics", value.publishDiagnostics, objectWriter);
	if(value.callHierarchy)
		writeJson("callHierarchy", value.callHierarchy, objectWriter);
	if(value.semanticTokens)
		writeJson("semanticTokens", value.semanticTokens, objectWriter);
	if(value.linkedEditingRange)
		writeJson("linkedEditingRange", value.linkedEditingRange, objectWriter);
	if(value.moniker)
		writeJson("moniker", value.moniker, objectWriter);
	if(value.typeHierarchy)
		writeJson("typeHierarchy", value.typeHierarchy, objectWriter);
	if(value.inlineValue)
		writeJson("inlineValue", value.inlineValue, objectWriter);
	if(value.inlayHint)
		writeJson("inlayHint", value.inlayHint, objectWriter);
	if(value.diagnostic)
		writeJson("diagnostic", value.diagnostic, objectWriter);
	if(value.inlineCompletion)
		writeJson("inlineCompletion", value.inlineCompletion, objectWriter);
}

void writeJson(const NotebookDocumentSyncClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.dynamicRegistration)
		writeJson("dynamicRegistration", value.dynamicRegistration, objectWriter);
	if(value.executionSummarySupport)
		writeJson("executionSummarySupport", value.executionSummarySupport, objectWriter);
}

void writeJson(const NotebookDocumentClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson("synchronization", value.synchronization, objectWriter);
}

void writeJson(const ClientShowMessageActionItemOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.additionalPropertiesSupport)
		writeJson("additionalPropertiesSupport", value.additionalPropertiesSupport, objectWriter);
}

void writeJson(const ShowMessageRequestClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.messageActionItem)
		writeJson("messageActionItem", value.messageActionItem, objectWriter);
}

void writeJson(const ShowDocumentClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson("support", value.support, objectWriter);
}

void writeJson(const WindowClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.showMessage)
		writeJson("showMessage", value.showMessage, objectWriter);
	if(value.showDocument)
		writeJson("showDocument", value.showDocument, objectWriter);
}

void writeJson(const StaleRequestSupportOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("cancel", value.cancel, objectWriter);
	writeJson("retryOnContentModified", value.retryOnContentModified, objectWriter);
}

void writeJson(const RegularExpressionsClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson("engine", value.engine, objectWriter);
	if(value.version)
		writeJson("version", value.version, objectWriter);
}

void writeJson(const MarkdownClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	writeJson("parser", value.parser, objectWriter);
	if(value.version)
		writeJson("version", value.version, objectWriter);
	if(value.allowedTags)
		writeJson("allowedTags", value.allowedTags, objectWriter);
}

void writeJson(const GeneralClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.staleRequestSupport)
		writeJson("staleRequestSupport", value.staleRequestSupport, objectWriter);
	if(value.regularExpressions)
		writeJson("regularExpressions", value.regularExpressions, objectWriter);
	if(value.markdown)
		writeJson("markdown", value.markdown, objectWriter);
	if(value.positionEncodings)
		writeJson("positionEncodings", value.positionEncodings, objectWriter);
}

void writeJson(const ClientCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.workspace)
		writeJson("workspace", value.workspace, objectWriter);
	if(value.textDocument)
		writeJson("textDocument", value.textDocument, objectWriter);
	if(value.notebookDocument)
		writeJson("notebookDocument", value.notebookDocument, objectWriter);
	if(value.window)
		writeJson("window", value.window, objectWriter);
	if(value.general)
		writeJson("general", value.general, objectWriter);
	if(value.experimental)
		writeJson("experimental", value.experimental, objectWriter);
}

void writeJson(const ClientInfo& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	if(value.version)
		writeJson("version", value.version, objectWriter);
}

void writeJson(const _InitializeParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("processId", value.processId, objectWriter);
	writeJson("rootUri", value.rootUri, objectWriter);
	writeJson("capabilities", value.capabilities, objectWriter);
	if(value.clientInfo)
		writeJson("clientInfo", value.clientInfo, objectWriter);
	if(value.locale)
		writeJson("locale", value.locale, objectWriter);
	if(value.rootPath)
		writeJson("rootPath", value.rootPath, objectWriter);
	if(value.initializationOptions)
		writeJson("initializationOptions", value.initializationOptions, objectWriter);
	if(value.trace)
		writeJson("trace", value.trace, objectWriter);
}

void writeJson(const WorkspaceFoldersInitializeParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workspaceFolders)
		writeJson("workspaceFolders", value.workspaceFolders, objectWriter);
}

void writeJson(const InitializeParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const _InitializeParams&>(value), objectWriter);
	writeJson(static_cast<const WorkspaceFoldersInitializeParams&>(value), objectWriter);
}

void writeJson(const SaveOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.includeText)
		writeJson("includeText", value.includeText, objectWriter);
}

void writeJson(const TextDocumentSyncOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.openClose)
		writeJson("openClose", value.openClose, objectWriter);
	if(value.change)
		writeJson("change", value.change, objectWriter);
	if(value.willSave)
		writeJson("willSave", value.willSave, objectWriter);
	if(value.willSaveWaitUntil)
		writeJson("willSaveWaitUntil", value.willSaveWaitUntil, objectWriter);
	if(value.save)
		writeJson("save", value.save, objectWriter);
}

void writeJson(const ServerCompletionItemOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.labelDetailsSupport)
		writeJson("labelDetailsSupport", value.labelDetailsSupport, objectWriter);
}

void writeJson(const CompletionOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.triggerCharacters)
		writeJson("triggerCharacters", value.triggerCharacters, objectWriter);
	if(value.allCommitCharacters)
		writeJson("allCommitCharacters", value.allCommitCharacters, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
	if(value.completionItem)
		writeJson("completionItem", value.completionItem, objectWriter);
}

void writeJson(const HoverOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const SignatureHelpOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.triggerCharacters)
		writeJson("triggerCharacters", value.triggerCharacters, objectWriter);
	if(value.retriggerCharacters)
		writeJson("retriggerCharacters", value.retriggerCharacters, objectWriter);
}

void writeJson(const DefinitionOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const ReferenceOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const DocumentHighlightOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const DocumentSymbolOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.label)
		writeJson("label", value.label, objectWriter);
}

void writeJson(const CodeActionKindDocumentation& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("command", value.command, objectWriter);
}

void writeJson(const CodeActionOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.codeActionKinds)
		writeJson("codeActionKinds", value.codeActionKinds, objectWriter);
	if(value.documentation)
		writeJson("documentation", value.documentation, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
}

void writeJson(const CodeLensOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
}

void writeJson(const DocumentLinkOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
}

void writeJson(const WorkspaceSymbolOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.resolveProvider)
		writeJson("resolveProvider", value.resolveProvider, objectWriter);
}

void writeJson(const DocumentFormattingOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
}

void writeJson(const DocumentRangeFormattingOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.rangesSupport)
		writeJson("rangesSupport", value.rangesSupport, objectWriter);
}

void writeJson(const DocumentOnTypeFormattingOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("firstTriggerCharacter", value.firstTriggerCharacter, objectWriter);
	if(value.moreTriggerCharacter)
		writeJson("moreTriggerCharacter", value.moreTriggerCharacter, objectWriter);
}

void writeJson(const RenameOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	if(value.prepareProvider)
		writeJson("prepareProvider", value.prepareProvider, objectWriter);
}

void writeJson(const ExecuteCommandOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneProgress)
		writeJson("workDoneProgress", value.workDoneProgress, objectWriter);
	writeJson("commands", value.commands, objectWriter);
}

void writeJson(const WorkspaceFoldersServerCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.supported)
		writeJson("supported", value.supported, objectWriter);
	if(value.changeNotifications)
		writeJson("changeNotifications", value.changeNotifications, objectWriter);
}

void writeJson(const FileOperationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.didCreate)
		writeJson("didCreate", value.didCreate, objectWriter);
	if(value.willCreate)
		writeJson("willCreate", value.willCreate, objectWriter);
	if(value.didRename)
		writeJson("didRename", value.didRename, objectWriter);
	if(value.willRename)
		writeJson("willRename", value.willRename, objectWriter);
	if(value.didDelete)
		writeJson("didDelete", value.didDelete, objectWriter);
	if(value.willDelete)
		writeJson("willDelete", value.willDelete, objectWriter);
}

void writeJson(const WorkspaceOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.workspaceFolders)
		writeJson("workspaceFolders", value.workspaceFolders, objectWriter);
	if(value.fileOperations)
		writeJson("fileOperations", value.fileOperations, objectWriter);
	if(value.textDocumentContent)
		writeJson("textDocumentContent", value.textDocumentContent, objectWriter);
}

void writeJson(const ServerCapabilities& value, json::ObjectWriter& objectWriter)
{
	if(value.positionEncoding)
		writeJson("positionEncoding", value.positionEncoding, objectWriter);
	if(value.textDocumentSync)
		writeJson("textDocumentSync", value.textDocumentSync, objectWriter);
	if(value.notebookDocumentSync)
		writeJson("notebookDocumentSync", value.notebookDocumentSync, objectWriter);
	if(value.completionProvider)
		writeJson("completionProvider", value.completionProvider, objectWriter);
	if(value.hoverProvider)
		writeJson("hoverProvider", value.hoverProvider, objectWriter);
	if(value.signatureHelpProvider)
		writeJson("signatureHelpProvider", value.signatureHelpProvider, objectWriter);
	if(value.declarationProvider)
		writeJson("declarationProvider", value.declarationProvider, objectWriter);
	if(value.definitionProvider)
		writeJson("definitionProvider", value.definitionProvider, objectWriter);
	if(value.typeDefinitionProvider)
		writeJson("typeDefinitionProvider", value.typeDefinitionProvider, objectWriter);
	if(value.implementationProvider)
		writeJson("implementationProvider", value.implementationProvider, objectWriter);
	if(value.referencesProvider)
		writeJson("referencesProvider", value.referencesProvider, objectWriter);
	if(value.documentHighlightProvider)
		writeJson("documentHighlightProvider", value.documentHighlightProvider, objectWriter);
	if(value.documentSymbolProvider)
		writeJson("documentSymbolProvider", value.documentSymbolProvider, objectWriter);
	if(value.codeActionProvider)
		writeJson("codeActionProvider", value.codeActionProvider, objectWriter);
	if(value.codeLensProvider)
		writeJson("codeLensProvider", value.codeLensProvider, objectWriter);
	if(value.documentLinkProvider)
		writeJson("documentLinkProvider", value.documentLinkProvider, objectWriter);
	if(value.colorProvider)
		writeJson("colorProvider", value.colorProvider, objectWriter);
	if(value.workspaceSymbolProvider)
		writeJson("workspaceSymbolProvider", value.workspaceSymbolProvider, objectWriter);
	if(value.documentFormattingProvider)
		writeJson("documentFormattingProvider", value.documentFormattingProvider, objectWriter);
	if(value.documentRangeFormattingProvider)
		writeJson("documentRangeFormattingProvider", value.documentRangeFormattingProvider, objectWriter);
	if(value.documentOnTypeFormattingProvider)
		writeJson("documentOnTypeFormattingProvider", value.documentOnTypeFormattingProvider, objectWriter);
	if(value.renameProvider)
		writeJson("renameProvider", value.renameProvider, objectWriter);
	if(value.foldingRangeProvider)
		writeJson("foldingRangeProvider", value.foldingRangeProvider, objectWriter);
	if(value.selectionRangeProvider)
		writeJson("selectionRangeProvider", value.selectionRangeProvider, objectWriter);
	if(value.executeCommandProvider)
		writeJson("executeCommandProvider", value.executeCommandProvider, objectWriter);
	if(value.callHierarchyProvider)
		writeJson("callHierarchyProvider", value.callHierarchyProvider, objectWriter);
	if(value.linkedEditingRangeProvider)
		writeJson("linkedEditingRangeProvider", value.linkedEditingRangeProvider, objectWriter);
	if(value.semanticTokensProvider)
		writeJson("semanticTokensProvider", value.semanticTokensProvider, objectWriter);
	if(value.monikerProvider)
		writeJson("monikerProvider", value.monikerProvider, objectWriter);
	if(value.typeHierarchyProvider)
		writeJson("typeHierarchyProvider", value.typeHierarchyProvider, objectWriter);
	if(value.inlineValueProvider)
		writeJson("inlineValueProvider", value.inlineValueProvider, objectWriter);
	if(value.inlayHintProvider)
		writeJson("inlayHintProvider", value.inlayHintProvider, objectWriter);
	if(value.diagnosticProvider)
		writeJson("diagnosticProvider", value.diagnosticProvider, objectWriter);
	if(value.inlineCompletionProvider)
		writeJson("inlineCompletionProvider", value.inlineCompletionProvider, objectWriter);
	if(value.workspace)
		writeJson("workspace", value.workspace, objectWriter);
	if(value.experimental)
		writeJson("experimental", value.experimental, objectWriter);
}

void writeJson(const ServerInfo& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	if(value.version)
		writeJson("version", value.version, objectWriter);
}

void writeJson(const InitializeResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("capabilities", value.capabilities, objectWriter);
	if(value.serverInfo)
		writeJson("serverInfo", value.serverInfo, objectWriter);
}

void writeJson(const InitializeError& value, json::ObjectWriter& objectWriter)
{
	writeJson("retry", value.retry, objectWriter);
}

void writeJson(const InitializedParams& value, json::ObjectWriter& objectWriter)
{
}

void writeJson(const DidChangeConfigurationParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("settings", value.settings, objectWriter);
}

void writeJson(const DidChangeConfigurationRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	if(value.section)
		writeJson("section", value.section, objectWriter);
}

void writeJson(const ShowMessageParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("type", value.type, objectWriter);
	writeJson("message", value.message, objectWriter);
}

void writeJson(const MessageActionItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("title", value.title, objectWriter);
}

void writeJson(const ShowMessageRequestParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("type", value.type, objectWriter);
	writeJson("message", value.message, objectWriter);
	if(value.actions)
		writeJson("actions", value.actions, objectWriter);
}

void writeJson(const LogMessageParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("type", value.type, objectWriter);
	writeJson("message", value.message, objectWriter);
}

void writeJson(const DidOpenTextDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const DidChangeTextDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("contentChanges", value.contentChanges, objectWriter);
}

void writeJson(const TextDocumentChangeRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson("syncKind", value.syncKind, objectWriter);
}

void writeJson(const DidCloseTextDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const DidSaveTextDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	if(value.text)
		writeJson("text", value.text, objectWriter);
}

void writeJson(const TextDocumentSaveRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const SaveOptions&>(value), objectWriter);
}

void writeJson(const WillSaveTextDocumentParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("reason", value.reason, objectWriter);
}

void writeJson(const FileEvent& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("type", value.type, objectWriter);
}

void writeJson(const DidChangeWatchedFilesParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("changes", value.changes, objectWriter);
}

void writeJson(const FileSystemWatcher& value, json::ObjectWriter& objectWriter)
{
	writeJson("globPattern", value.globPattern, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
}

void writeJson(const DidChangeWatchedFilesRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("watchers", value.watchers, objectWriter);
}

void writeJson(const PublishDiagnosticsParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
	writeJson("diagnostics", value.diagnostics, objectWriter);
	if(value.version)
		writeJson("version", value.version, objectWriter);
}

void writeJson(const CompletionContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("triggerKind", value.triggerKind, objectWriter);
	if(value.triggerCharacter)
		writeJson("triggerCharacter", value.triggerCharacter, objectWriter);
}

void writeJson(const CompletionParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	if(value.context)
		writeJson("context", value.context, objectWriter);
}

void writeJson(const CompletionItemLabelDetails& value, json::ObjectWriter& objectWriter)
{
	if(value.detail)
		writeJson("detail", value.detail, objectWriter);
	if(value.description)
		writeJson("description", value.description, objectWriter);
}

void writeJson(const InsertReplaceEdit& value, json::ObjectWriter& objectWriter)
{
	writeJson("newText", value.newText, objectWriter);
	writeJson("insert", value.insert, objectWriter);
	writeJson("replace", value.replace, objectWriter);
}

void writeJson(const CompletionItem& value, json::ObjectWriter& objectWriter)
{
	writeJson("label", value.label, objectWriter);
	if(value.labelDetails)
		writeJson("labelDetails", value.labelDetails, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.detail)
		writeJson("detail", value.detail, objectWriter);
	if(value.documentation)
		writeJson("documentation", value.documentation, objectWriter);
	if(value.deprecated)
		writeJson("deprecated", value.deprecated, objectWriter);
	if(value.preselect)
		writeJson("preselect", value.preselect, objectWriter);
	if(value.sortText)
		writeJson("sortText", value.sortText, objectWriter);
	if(value.filterText)
		writeJson("filterText", value.filterText, objectWriter);
	if(value.insertText)
		writeJson("insertText", value.insertText, objectWriter);
	if(value.insertTextFormat)
		writeJson("insertTextFormat", value.insertTextFormat, objectWriter);
	if(value.insertTextMode)
		writeJson("insertTextMode", value.insertTextMode, objectWriter);
	if(value.textEdit)
		writeJson("textEdit", value.textEdit, objectWriter);
	if(value.textEditText)
		writeJson("textEditText", value.textEditText, objectWriter);
	if(value.additionalTextEdits)
		writeJson("additionalTextEdits", value.additionalTextEdits, objectWriter);
	if(value.commitCharacters)
		writeJson("commitCharacters", value.commitCharacters, objectWriter);
	if(value.command)
		writeJson("command", value.command, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const EditRangeWithInsertReplace& value, json::ObjectWriter& objectWriter)
{
	writeJson("insert", value.insert, objectWriter);
	writeJson("replace", value.replace, objectWriter);
}

void writeJson(const CompletionItemDefaults& value, json::ObjectWriter& objectWriter)
{
	if(value.commitCharacters)
		writeJson("commitCharacters", value.commitCharacters, objectWriter);
	if(value.editRange)
		writeJson("editRange", value.editRange, objectWriter);
	if(value.insertTextFormat)
		writeJson("insertTextFormat", value.insertTextFormat, objectWriter);
	if(value.insertTextMode)
		writeJson("insertTextMode", value.insertTextMode, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const CompletionItemApplyKinds& value, json::ObjectWriter& objectWriter)
{
	if(value.commitCharacters)
		writeJson("commitCharacters", value.commitCharacters, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const CompletionList& value, json::ObjectWriter& objectWriter)
{
	writeJson("isIncomplete", value.isIncomplete, objectWriter);
	writeJson("items", value.items, objectWriter);
	if(value.itemDefaults)
		writeJson("itemDefaults", value.itemDefaults, objectWriter);
	if(value.applyKind)
		writeJson("applyKind", value.applyKind, objectWriter);
}

void writeJson(const CompletionRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const CompletionOptions&>(value), objectWriter);
}

void writeJson(const HoverParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const MarkedStringWithLanguage& value, json::ObjectWriter& objectWriter)
{
	writeJson("language", value.language, objectWriter);
	writeJson("value", value.value, objectWriter);
}

void writeJson(const Hover& value, json::ObjectWriter& objectWriter)
{
	writeJson("contents", value.contents, objectWriter);
	if(value.range)
		writeJson("range", value.range, objectWriter);
}

void writeJson(const HoverRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const HoverOptions&>(value), objectWriter);
}

void writeJson(const ParameterInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson("label", value.label, objectWriter);
	if(value.documentation)
		writeJson("documentation", value.documentation, objectWriter);
}

void writeJson(const SignatureInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson("label", value.label, objectWriter);
	if(value.documentation)
		writeJson("documentation", value.documentation, objectWriter);
	if(value.parameters)
		writeJson("parameters", value.parameters, objectWriter);
	if(value.activeParameter)
		writeJson("activeParameter", value.activeParameter, objectWriter);
}

void writeJson(const SignatureHelp& value, json::ObjectWriter& objectWriter)
{
	writeJson("signatures", value.signatures, objectWriter);
	if(value.activeSignature)
		writeJson("activeSignature", value.activeSignature, objectWriter);
	if(value.activeParameter)
		writeJson("activeParameter", value.activeParameter, objectWriter);
}

void writeJson(const SignatureHelpContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("triggerKind", value.triggerKind, objectWriter);
	writeJson("isRetrigger", value.isRetrigger, objectWriter);
	if(value.triggerCharacter)
		writeJson("triggerCharacter", value.triggerCharacter, objectWriter);
	if(value.activeSignatureHelp)
		writeJson("activeSignatureHelp", value.activeSignatureHelp, objectWriter);
}

void writeJson(const SignatureHelpParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.context)
		writeJson("context", value.context, objectWriter);
}

void writeJson(const SignatureHelpRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const SignatureHelpOptions&>(value), objectWriter);
}

void writeJson(const DefinitionParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const DefinitionRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DefinitionOptions&>(value), objectWriter);
}

void writeJson(const ReferenceContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("includeDeclaration", value.includeDeclaration, objectWriter);
}

void writeJson(const ReferenceParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("context", value.context, objectWriter);
}

void writeJson(const ReferenceRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const ReferenceOptions&>(value), objectWriter);
}

void writeJson(const DocumentHighlightParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
}

void writeJson(const DocumentHighlight& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
}

void writeJson(const DocumentHighlightRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentHighlightOptions&>(value), objectWriter);
}

void writeJson(const DocumentSymbolParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const BaseSymbolInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	writeJson("kind", value.kind, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.containerName)
		writeJson("containerName", value.containerName, objectWriter);
}

void writeJson(const SymbolInformation& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const BaseSymbolInformation&>(value), objectWriter);
	writeJson("location", value.location, objectWriter);
	if(value.deprecated)
		writeJson("deprecated", value.deprecated, objectWriter);
}

void writeJson(const DocumentSymbol& value, json::ObjectWriter& objectWriter)
{
	writeJson("name", value.name, objectWriter);
	writeJson("kind", value.kind, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("selectionRange", value.selectionRange, objectWriter);
	if(value.detail)
		writeJson("detail", value.detail, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
	if(value.deprecated)
		writeJson("deprecated", value.deprecated, objectWriter);
	if(value.children)
		writeJson("children", value.children, objectWriter);
}

void writeJson(const DocumentSymbolRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentSymbolOptions&>(value), objectWriter);
}

void writeJson(const CodeActionContext& value, json::ObjectWriter& objectWriter)
{
	writeJson("diagnostics", value.diagnostics, objectWriter);
	if(value.only)
		writeJson("only", value.only, objectWriter);
	if(value.triggerKind)
		writeJson("triggerKind", value.triggerKind, objectWriter);
}

void writeJson(const CodeActionParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("context", value.context, objectWriter);
}

void writeJson(const CodeActionDisabled& value, json::ObjectWriter& objectWriter)
{
	writeJson("reason", value.reason, objectWriter);
}

void writeJson(const CodeAction& value, json::ObjectWriter& objectWriter)
{
	writeJson("title", value.title, objectWriter);
	if(value.kind)
		writeJson("kind", value.kind, objectWriter);
	if(value.diagnostics)
		writeJson("diagnostics", value.diagnostics, objectWriter);
	if(value.isPreferred)
		writeJson("isPreferred", value.isPreferred, objectWriter);
	if(value.disabled)
		writeJson("disabled", value.disabled, objectWriter);
	if(value.edit)
		writeJson("edit", value.edit, objectWriter);
	if(value.command)
		writeJson("command", value.command, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
	if(value.tags)
		writeJson("tags", value.tags, objectWriter);
}

void writeJson(const CodeActionRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const CodeActionOptions&>(value), objectWriter);
}

void writeJson(const WorkspaceSymbolParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("query", value.query, objectWriter);
}

void writeJson(const LocationUriOnly& value, json::ObjectWriter& objectWriter)
{
	writeJson("uri", value.uri, objectWriter);
}

void writeJson(const WorkspaceSymbol& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const BaseSymbolInformation&>(value), objectWriter);
	writeJson("location", value.location, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const WorkspaceSymbolRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const WorkspaceSymbolOptions&>(value), objectWriter);
}

void writeJson(const CodeLensParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const CodeLens& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	if(value.command)
		writeJson("command", value.command, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const CodeLensRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const CodeLensOptions&>(value), objectWriter);
}

void writeJson(const DocumentLinkParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	if(value.partialResultToken)
		writeJson("partialResultToken", value.partialResultToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
}

void writeJson(const DocumentLink& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	if(value.target)
		writeJson("target", value.target, objectWriter);
	if(value.tooltip)
		writeJson("tooltip", value.tooltip, objectWriter);
	if(value.data)
		writeJson("data", value.data, objectWriter);
}

void writeJson(const DocumentLinkRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentLinkOptions&>(value), objectWriter);
}

void writeJson(const FormattingOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson("tabSize", value.tabSize, objectWriter);
	writeJson("insertSpaces", value.insertSpaces, objectWriter);
	if(value.trimTrailingWhitespace)
		writeJson("trimTrailingWhitespace", value.trimTrailingWhitespace, objectWriter);
	if(value.insertFinalNewline)
		writeJson("insertFinalNewline", value.insertFinalNewline, objectWriter);
	if(value.trimFinalNewlines)
		writeJson("trimFinalNewlines", value.trimFinalNewlines, objectWriter);
}

void writeJson(const DocumentFormattingParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("options", value.options, objectWriter);
}

void writeJson(const DocumentFormattingRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentFormattingOptions&>(value), objectWriter);
}

void writeJson(const DocumentRangeFormattingParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("range", value.range, objectWriter);
	writeJson("options", value.options, objectWriter);
}

void writeJson(const DocumentRangeFormattingRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentRangeFormattingOptions&>(value), objectWriter);
}

void writeJson(const DocumentRangesFormattingParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("ranges", value.ranges, objectWriter);
	writeJson("options", value.options, objectWriter);
}

void writeJson(const DocumentOnTypeFormattingParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("textDocument", value.textDocument, objectWriter);
	writeJson("position", value.position, objectWriter);
	writeJson("ch", value.ch, objectWriter);
	writeJson("options", value.options, objectWriter);
}

void writeJson(const DocumentOnTypeFormattingRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const DocumentOnTypeFormattingOptions&>(value), objectWriter);
}

void writeJson(const RenameParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("newName", value.newName, objectWriter);
}

void writeJson(const RenameRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentRegistrationOptions&>(value), objectWriter);
	writeJson(static_cast<const RenameOptions&>(value), objectWriter);
}

void writeJson(const PrepareRenameParams& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const TextDocumentPositionParams&>(value), objectWriter);
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
}

void writeJson(const ExecuteCommandParams& value, json::ObjectWriter& objectWriter)
{
	if(value.workDoneToken)
		writeJson("workDoneToken", value.workDoneToken, objectWriter);
	writeJson("command", value.command, objectWriter);
	if(value.arguments)
		writeJson("arguments", value.arguments, objectWriter);
}

void writeJson(const ExecuteCommandRegistrationOptions& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const ExecuteCommandOptions&>(value), objectWriter);
}

void writeJson(const WorkspaceEditMetadata& value, json::ObjectWriter& objectWriter)
{
	if(value.isRefactoring)
		writeJson("isRefactoring", value.isRefactoring, objectWriter);
}

void writeJson(const ApplyWorkspaceEditParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("edit", value.edit, objectWriter);
	if(value.label)
		writeJson("label", value.label, objectWriter);
	if(value.metadata)
		writeJson("metadata", value.metadata, objectWriter);
}

void writeJson(const ApplyWorkspaceEditResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("applied", value.applied, objectWriter);
	if(value.failureReason)
		writeJson("failureReason", value.failureReason, objectWriter);
	if(value.failedChange)
		writeJson("failedChange", value.failedChange, objectWriter);
}

void writeJson(const WorkDoneProgressBegin& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	writeJson("title", value.title, objectWriter);
	if(value.cancellable)
		writeJson("cancellable", value.cancellable, objectWriter);
	if(value.message)
		writeJson("message", value.message, objectWriter);
	if(value.percentage)
		writeJson("percentage", value.percentage, objectWriter);
}

void writeJson(const WorkDoneProgressReport& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	if(value.cancellable)
		writeJson("cancellable", value.cancellable, objectWriter);
	if(value.message)
		writeJson("message", value.message, objectWriter);
	if(value.percentage)
		writeJson("percentage", value.percentage, objectWriter);
}

void writeJson(const WorkDoneProgressEnd& value, json::ObjectWriter& objectWriter)
{
	writeJson("kind", value.kind, objectWriter);
	if(value.message)
		writeJson("message", value.message, objectWriter);
}

void writeJson(const SetTraceParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("value", value.value, objectWriter);
}

void writeJson(const LogTraceParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("message", value.message, objectWriter);
	if(value.verbose)
		writeJson("verbose", value.verbose, objectWriter);
}

void writeJson(const CancelParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("id", value.id, objectWriter);
}

void writeJson(const ProgressParams& value, json::ObjectWriter& objectWriter)
{
	writeJson("token", value.token, objectWriter);
	writeJson("value", value.value, objectWriter);
}

void writeJson(const LocationLink& value, json::ObjectWriter& objectWriter)
{
	writeJson("targetUri", value.targetUri, objectWriter);
	writeJson("targetRange", value.targetRange, objectWriter);
	writeJson("targetSelectionRange", value.targetSelectionRange, objectWriter);
	if(value.originSelectionRange)
		writeJson("originSelectionRange", value.originSelectionRange, objectWriter);
}

void writeJson(const InlineValueText& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("text", value.text, objectWriter);
}

void writeJson(const InlineValueVariableLookup& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("caseSensitiveLookup", value.caseSensitiveLookup, objectWriter);
	if(value.variableName)
		writeJson("variableName", value.variableName, objectWriter);
}

void writeJson(const InlineValueEvaluatableExpression& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	if(value.expression)
		writeJson("expression", value.expression, objectWriter);
}

void writeJson(const RelatedFullDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const FullDocumentDiagnosticReport&>(value), objectWriter);
	if(value.relatedDocuments)
		writeJson("relatedDocuments", value.relatedDocuments, objectWriter);
}

void writeJson(const RelatedUnchangedDocumentDiagnosticReport& value, json::ObjectWriter& objectWriter)
{
	writeJson(static_cast<const UnchangedDocumentDiagnosticReport&>(value), objectWriter);
	if(value.relatedDocuments)
		writeJson("relatedDocuments", value.relatedDocuments, objectWriter);
}

void writeJson(const DocumentDiagnosticReportPartialResult& value, json::ObjectWriter& objectWriter)
{
	writeJson("relatedDocuments", value.relatedDocuments, objectWriter);
}

void writeJson(const PrepareRenamePlaceholder& value, json::ObjectWriter& objectWriter)
{
	writeJson("range", value.range, objectWriter);
	writeJson("placeholder", value.placeholder, objectWriter);
}

void writeJson(const PrepareRenameDefaultBehavior& value, json::ObjectWriter& objectWriter)
{
	writeJson("defaultBehavior", value.defaultBehavior, objectWriter);
}

#if defined(__clang__) || defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif
} // namespace lsp
