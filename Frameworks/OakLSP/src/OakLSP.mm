#import "OakLSP.h"
#include <lsp/types.h>
#include <lsp/version.h>
#include <lsp/protocol_version.h>
#include <lsp/json/parser.h>
#include <lsp/json/writer.h>
#include <stdexcept>
#include <unistd.h>

NSString* OakLSPBuildCheck ()
{
	for(auto const& source : {R"({"title":"Synthesize","command":{"title":"Synthesize","command":"aeon.synthesize","arguments":[]}})", R"({"title":"Command","command":"example.run"})", R"({"title":"Edit","edit":{"changes":{}}})"}) {
		lsp::json::Parser parser(source);
		lsp::OneOf<lsp::Command, lsp::CodeAction> action;
		lsp::fromJson(parser.parse(), action);
		bool plain = std::string_view(source).find("example.run") != std::string_view::npos;
		if(std::holds_alternative<lsp::Command>(action) != plain) throw std::runtime_error("CodeAction/Command discrimination failed");
	}
	auto uri = lsp::Uri::fileUriFromPath("/tmp/TextMate LSP/ação.c");
	if(lsp::Uri::parse(uri.toString()).fsPath() != "/tmp/TextMate LSP/ação.c")
		throw std::runtime_error("LSP URI round trip failed");

	lsp::InitializeParams params;
	params.processId = getpid();
	params.rootUri = uri;
	std::string encoded;
	{
		lsp::json::Writer writer(encoded);
		auto object = writer.beginObject();
		lsp::writeJson(params, object);
	}

	lsp::InitializeParams decoded;
	lsp::json::Parser parser(encoded);
	lsp::fromJson(parser.parse(), decoded);
	if(decoded.rootUri.isNull() || decoded.rootUri.value() != uri ||
	   decoded.processId.isNull() || decoded.processId.value() != getpid())
		throw std::runtime_error("LSP initialize serialization round trip failed");

	std::string number;
	lsp::json::Writer(number).write(1.25);
	if(number != "1.25")
		throw std::runtime_error("LSP floating-point JSON serialization failed");

	return [NSString stringWithFormat:@"lsp-framework %s; LSP %s; Objective-C++/JSON/URI OK", LSP_VERSION_STR, LSP_PROTOCOL_VERSION_STR];
}
