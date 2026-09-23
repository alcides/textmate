/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#pragma once

#include <string_view>
#include <lsp/message_base.h>
#include <lsp/types.h>

namespace lsp{

/*
 * Request messages
 */

namespace requests{

/*
 * callHierarchy/incomingCalls
 *
 * A request to resolve the incoming calls for a given `CallHierarchyItem`.
 * 
 * @since 3.16.0
 */
struct CallHierarchyIncomingCalls{
	static constexpr auto Method           = std::string_view("callHierarchy/incomingCalls");
	static constexpr auto ClientCapability = std::string_view("textDocument.callHierarchy");
	static constexpr auto ServerCapability = std::string_view("callHierarchyProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::CallHierarchyIncomingCallsPartialResult;
	using Params = lsp::CallHierarchyIncomingCallsParams;
	using Result = lsp::CallHierarchyIncomingCallsResult;
};

/*
 * callHierarchy/outgoingCalls
 *
 * A request to resolve the outgoing calls for a given `CallHierarchyItem`.
 * 
 * @since 3.16.0
 */
struct CallHierarchyOutgoingCalls{
	static constexpr auto Method           = std::string_view("callHierarchy/outgoingCalls");
	static constexpr auto ClientCapability = std::string_view("textDocument.callHierarchy");
	static constexpr auto ServerCapability = std::string_view("callHierarchyProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::CallHierarchyOutgoingCallsPartialResult;
	using Params = lsp::CallHierarchyOutgoingCallsParams;
	using Result = lsp::CallHierarchyOutgoingCallsResult;
};

/*
 * client/registerCapability
 *
 * The `client/registerCapability` request is sent from the server to the client to register a new capability
 * handler on the client side.
 */
struct ClientRegisterCapability{
	static constexpr auto Method           = std::string_view("client/registerCapability");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::RegistrationParams;
	using Result = lsp::ClientRegisterCapabilityResult;
};

/*
 * client/unregisterCapability
 *
 * The `client/unregisterCapability` request is sent from the server to the client to unregister a previously registered capability
 * handler on the client side.
 */
struct ClientUnregisterCapability{
	static constexpr auto Method           = std::string_view("client/unregisterCapability");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::UnregistrationParams;
	using Result = lsp::ClientUnregisterCapabilityResult;
};

/*
 * codeAction/resolve
 *
 * Request to resolve additional information for a given code action.The request's
 * parameter is of type {@link CodeAction} the response
 * is of type {@link CodeAction} or a Thenable that resolves to such.
 */
struct CodeActionResolve{
	static constexpr auto Method           = std::string_view("codeAction/resolve");
	static constexpr auto ClientCapability = std::string_view("textDocument.codeAction.resolveSupport");
	static constexpr auto ServerCapability = std::string_view("codeActionProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::CodeAction;
	using Result = lsp::CodeAction;
};

/*
 * codeLens/resolve
 *
 * A request to resolve a command for a given code lens.
 */
struct CodeLensResolve{
	static constexpr auto Method           = std::string_view("codeLens/resolve");
	static constexpr auto ClientCapability = std::string_view("textDocument.codeLens.resolveSupport");
	static constexpr auto ServerCapability = std::string_view("codeLensProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::CodeLens;
	using Result = lsp::CodeLens;
};

/*
 * completionItem/resolve
 *
 * Request to resolve additional information for a given completion item.The request's
 * parameter is of type {@link CompletionItem} the response
 * is of type {@link CompletionItem} or a Thenable that resolves to such.
 */
struct CompletionItemResolve{
	static constexpr auto Method           = std::string_view("completionItem/resolve");
	static constexpr auto ClientCapability = std::string_view("textDocument.completion.completionItem.resolveSupport");
	static constexpr auto ServerCapability = std::string_view("completionProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::CompletionItem;
	using Result = lsp::CompletionItem;
};

/*
 * documentLink/resolve
 *
 * Request to resolve additional information for a given document link. The request's
 * parameter is of type {@link DocumentLink} the response
 * is of type {@link DocumentLink} or a Thenable that resolves to such.
 */
struct DocumentLinkResolve{
	static constexpr auto Method           = std::string_view("documentLink/resolve");
	static constexpr auto ClientCapability = std::string_view("textDocument.documentLink");
	static constexpr auto ServerCapability = std::string_view("documentLinkProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::DocumentLink;
	using Result = lsp::DocumentLink;
};

/*
 * initialize
 *
 * The initialize request is sent from the client to the server.
 * It is sent once as the request after starting up the server.
 * The requests parameter is of type {@link InitializeParams}
 * the response if of type {@link InitializeResult} of a Thenable that
 * resolves to such.
 */
struct Initialize{
	static constexpr auto Method           = std::string_view("initialize");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using ErrorData = lsp::InitializeError;
	using Params = lsp::InitializeParams;
	using Result = lsp::InitializeResult;
};

/*
 * inlayHint/resolve
 *
 * A request to resolve additional properties for an inlay hint.
 * The request's parameter is of type {@link InlayHint}, the response is
 * of type {@link InlayHint} or a Thenable that resolves to such.
 * 
 * @since 3.17.0
 */
struct InlayHintResolve{
	static constexpr auto Method           = std::string_view("inlayHint/resolve");
	static constexpr auto ClientCapability = std::string_view("textDocument.inlayHint.resolveSupport");
	static constexpr auto ServerCapability = std::string_view("inlayHintProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::InlayHint;
	using Result = lsp::InlayHint;
};

/*
 * shutdown
 *
 * A shutdown request is sent from the client to the server.
 * It is sent once when the client decides to shutdown the
 * server. The only notification that is sent after a shutdown request
 * is the exit event.
 */
struct Shutdown{
	static constexpr auto Method           = std::string_view("shutdown");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Result = lsp::ShutdownResult;
};

/*
 * textDocument/codeAction
 *
 * A request to provide commands for the given text document and range.
 */
struct TextDocumentCodeAction{
	static constexpr auto Method           = std::string_view("textDocument/codeAction");
	static constexpr auto ClientCapability = std::string_view("textDocument.codeAction");
	static constexpr auto ServerCapability = std::string_view("codeActionProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::CodeActionRegistrationOptions;
	using PartialResult = lsp::TextDocumentCodeActionPartialResult;
	using Params = lsp::CodeActionParams;
	using Result = lsp::TextDocumentCodeActionResult;
};

/*
 * textDocument/codeLens
 *
 * A request to provide code lens for the given text document.
 */
struct TextDocumentCodeLens{
	static constexpr auto Method           = std::string_view("textDocument/codeLens");
	static constexpr auto ClientCapability = std::string_view("textDocument.codeLens");
	static constexpr auto ServerCapability = std::string_view("codeLensProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::CodeLensRegistrationOptions;
	using PartialResult = lsp::TextDocumentCodeLensPartialResult;
	using Params = lsp::CodeLensParams;
	using Result = lsp::TextDocumentCodeLensResult;
};

/*
 * textDocument/colorPresentation
 *
 * A request to list all presentation for a color. The request's
 * parameter is of type {@link ColorPresentationParams} the
 * response is of type {@link ColorPresentation ColorPresentation[]} or a Thenable
 * that resolves to such.
 */
struct TextDocumentColorPresentation{
	static constexpr auto Method           = std::string_view("textDocument/colorPresentation");
	static constexpr auto ClientCapability = std::string_view("textDocument.colorProvider");
	static constexpr auto ServerCapability = std::string_view("colorProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentColorRegistrationOptions;
	using PartialResult = lsp::TextDocumentColorPresentationPartialResult;
	using Params = lsp::ColorPresentationParams;
	using Result = lsp::TextDocumentColorPresentationResult;
};

/*
 * textDocument/completion
 *
 * Request to request completion at a given text document position. The request's
 * parameter is of type {@link TextDocumentPosition} the response
 * is of type {@link CompletionItem CompletionItem[]} or {@link CompletionList}
 * or a Thenable that resolves to such.
 * 
 * The request can delay the computation of the {@link CompletionItem.detail `detail`}
 * and {@link CompletionItem.documentation `documentation`} properties to the `completionItem/resolve`
 * request. However, properties that are needed for the initial sorting and filtering, like `sortText`,
 * `filterText`, `insertText`, and `textEdit`, must not be changed during resolve.
 */
struct TextDocumentCompletion{
	static constexpr auto Method           = std::string_view("textDocument/completion");
	static constexpr auto ClientCapability = std::string_view("textDocument.completion");
	static constexpr auto ServerCapability = std::string_view("completionProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::CompletionRegistrationOptions;
	using PartialResult = lsp::TextDocumentCompletionPartialResult;
	using Params = lsp::CompletionParams;
	using Result = lsp::TextDocumentCompletionResult;
};

/*
 * textDocument/declaration
 *
 * A request to resolve the type definition locations of a symbol at a given text
 * document position. The request's parameter is of type {@link TextDocumentPositionParams}
 * the response is of type {@link Declaration} or a typed array of {@link DeclarationLink}
 * or a Thenable that resolves to such.
 */
struct TextDocumentDeclaration{
	static constexpr auto Method           = std::string_view("textDocument/declaration");
	static constexpr auto ClientCapability = std::string_view("textDocument.declaration");
	static constexpr auto ServerCapability = std::string_view("declarationProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DeclarationRegistrationOptions;
	using PartialResult = lsp::TextDocumentDeclarationPartialResult;
	using Params = lsp::DeclarationParams;
	using Result = lsp::TextDocumentDeclarationResult;
};

/*
 * textDocument/definition
 *
 * A request to resolve the definition location of a symbol at a given text
 * document position. The request's parameter is of type {@link TextDocumentPosition}
 * the response is of either type {@link Definition} or a typed array of
 * {@link DefinitionLink} or a Thenable that resolves to such.
 */
struct TextDocumentDefinition{
	static constexpr auto Method           = std::string_view("textDocument/definition");
	static constexpr auto ClientCapability = std::string_view("textDocument.definition");
	static constexpr auto ServerCapability = std::string_view("definitionProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DefinitionRegistrationOptions;
	using PartialResult = lsp::TextDocumentDefinitionPartialResult;
	using Params = lsp::DefinitionParams;
	using Result = lsp::TextDocumentDefinitionResult;
};

/*
 * textDocument/diagnostic
 *
 * The document diagnostic request definition.
 * 
 * 
 * @since 3.17.0
 */
struct TextDocumentDiagnostic{
	static constexpr auto Method           = std::string_view("textDocument/diagnostic");
	static constexpr auto ClientCapability = std::string_view("textDocument.diagnostic");
	static constexpr auto ServerCapability = std::string_view("diagnosticProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DiagnosticRegistrationOptions;
	using PartialResult = lsp::DocumentDiagnosticReportProgress;
	using ErrorData = lsp::DiagnosticServerCancellationData;
	using Params = lsp::DocumentDiagnosticParams;
	using Result = lsp::DocumentDiagnosticReport;
};

/*
 * textDocument/documentColor
 *
 * A request to list all color symbols found in a given text document. The request's
 * parameter is of type {@link DocumentColorParams} the
 * response is of type {@link ColorInformation ColorInformation[]} or a Thenable
 * that resolves to such.
 */
struct TextDocumentDocumentColor{
	static constexpr auto Method           = std::string_view("textDocument/documentColor");
	static constexpr auto ClientCapability = std::string_view("textDocument.colorProvider");
	static constexpr auto ServerCapability = std::string_view("colorProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentColorRegistrationOptions;
	using PartialResult = lsp::TextDocumentDocumentColorPartialResult;
	using Params = lsp::DocumentColorParams;
	using Result = lsp::TextDocumentDocumentColorResult;
};

/*
 * textDocument/documentHighlight
 *
 * Request to resolve a {@link DocumentHighlight} for a given
 * text document position. The request's parameter is of type {@link TextDocumentPosition}
 * the request response is an array of type {@link DocumentHighlight}
 * or a Thenable that resolves to such.
 */
struct TextDocumentDocumentHighlight{
	static constexpr auto Method           = std::string_view("textDocument/documentHighlight");
	static constexpr auto ClientCapability = std::string_view("textDocument.documentHighlight");
	static constexpr auto ServerCapability = std::string_view("documentHighlightProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentHighlightRegistrationOptions;
	using PartialResult = lsp::TextDocumentDocumentHighlightPartialResult;
	using Params = lsp::DocumentHighlightParams;
	using Result = lsp::TextDocumentDocumentHighlightResult;
};

/*
 * textDocument/documentLink
 *
 * A request to provide document links
 */
struct TextDocumentDocumentLink{
	static constexpr auto Method           = std::string_view("textDocument/documentLink");
	static constexpr auto ClientCapability = std::string_view("textDocument.documentLink");
	static constexpr auto ServerCapability = std::string_view("documentLinkProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentLinkRegistrationOptions;
	using PartialResult = lsp::TextDocumentDocumentLinkPartialResult;
	using Params = lsp::DocumentLinkParams;
	using Result = lsp::TextDocumentDocumentLinkResult;
};

/*
 * textDocument/documentSymbol
 *
 * A request to list all symbols found in a given text document. The request's
 * parameter is of type {@link TextDocumentIdentifier} the
 * response is of type {@link SymbolInformation SymbolInformation[]} or a Thenable
 * that resolves to such.
 */
struct TextDocumentDocumentSymbol{
	static constexpr auto Method           = std::string_view("textDocument/documentSymbol");
	static constexpr auto ClientCapability = std::string_view("textDocument.documentSymbol");
	static constexpr auto ServerCapability = std::string_view("documentSymbolProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentSymbolRegistrationOptions;
	using PartialResult = lsp::TextDocumentDocumentSymbolPartialResult;
	using Params = lsp::DocumentSymbolParams;
	using Result = lsp::TextDocumentDocumentSymbolResult;
};

/*
 * textDocument/foldingRange
 *
 * A request to provide folding ranges in a document. The request's
 * parameter is of type {@link FoldingRangeParams}, the
 * response is of type {@link FoldingRangeList} or a Thenable
 * that resolves to such.
 */
struct TextDocumentFoldingRange{
	static constexpr auto Method           = std::string_view("textDocument/foldingRange");
	static constexpr auto ClientCapability = std::string_view("textDocument.foldingRange");
	static constexpr auto ServerCapability = std::string_view("foldingRangeProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FoldingRangeRegistrationOptions;
	using PartialResult = lsp::TextDocumentFoldingRangePartialResult;
	using Params = lsp::FoldingRangeParams;
	using Result = lsp::TextDocumentFoldingRangeResult;
};

/*
 * textDocument/formatting
 *
 * A request to format a whole document.
 */
struct TextDocumentFormatting{
	static constexpr auto Method           = std::string_view("textDocument/formatting");
	static constexpr auto ClientCapability = std::string_view("textDocument.formatting");
	static constexpr auto ServerCapability = std::string_view("documentFormattingProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentFormattingRegistrationOptions;
	using Params = lsp::DocumentFormattingParams;
	using Result = lsp::TextDocumentFormattingResult;
};

/*
 * textDocument/hover
 *
 * Request to request hover information at a given text document position. The request's
 * parameter is of type {@link TextDocumentPosition} the response is of
 * type {@link Hover} or a Thenable that resolves to such.
 */
struct TextDocumentHover{
	static constexpr auto Method           = std::string_view("textDocument/hover");
	static constexpr auto ClientCapability = std::string_view("textDocument.hover");
	static constexpr auto ServerCapability = std::string_view("hoverProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::HoverRegistrationOptions;
	using Params = lsp::HoverParams;
	using Result = lsp::TextDocumentHoverResult;
};

/*
 * textDocument/implementation
 *
 * A request to resolve the implementation locations of a symbol at a given text
 * document position. The request's parameter is of type {@link TextDocumentPositionParams}
 * the response is of type {@link Definition} or a Thenable that resolves to such.
 */
struct TextDocumentImplementation{
	static constexpr auto Method           = std::string_view("textDocument/implementation");
	static constexpr auto ClientCapability = std::string_view("textDocument.implementation");
	static constexpr auto ServerCapability = std::string_view("implementationProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::ImplementationRegistrationOptions;
	using PartialResult = lsp::TextDocumentImplementationPartialResult;
	using Params = lsp::ImplementationParams;
	using Result = lsp::TextDocumentImplementationResult;
};

/*
 * textDocument/inlayHint
 *
 * A request to provide inlay hints in a document. The request's parameter is of
 * type {@link InlayHintsParams}, the response is of type
 * {@link InlayHint InlayHint[]} or a Thenable that resolves to such.
 * 
 * @since 3.17.0
 */
struct TextDocumentInlayHint{
	static constexpr auto Method           = std::string_view("textDocument/inlayHint");
	static constexpr auto ClientCapability = std::string_view("textDocument.inlayHint");
	static constexpr auto ServerCapability = std::string_view("inlayHintProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::InlayHintRegistrationOptions;
	using PartialResult = lsp::TextDocumentInlayHintPartialResult;
	using Params = lsp::InlayHintParams;
	using Result = lsp::TextDocumentInlayHintResult;
};

/*
 * textDocument/inlineCompletion
 *
 * A request to provide inline completions in a document. The request's parameter is of
 * type {@link InlineCompletionParams}, the response is of type
 * {@link InlineCompletion InlineCompletion[]} or a Thenable that resolves to such.
 * 
 * @since 3.18.0
 */
struct TextDocumentInlineCompletion{
	static constexpr auto Method           = std::string_view("textDocument/inlineCompletion");
	static constexpr auto ClientCapability = std::string_view("textDocument.inlineCompletion");
	static constexpr auto ServerCapability = std::string_view("inlineCompletionProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::InlineCompletionRegistrationOptions;
	using PartialResult = lsp::TextDocumentInlineCompletionPartialResult;
	using Params = lsp::InlineCompletionParams;
	using Result = lsp::TextDocumentInlineCompletionResult;
};

/*
 * textDocument/inlineValue
 *
 * A request to provide inline values in a document. The request's parameter is of
 * type {@link InlineValueParams}, the response is of type
 * {@link InlineValue InlineValue[]} or a Thenable that resolves to such.
 * 
 * @since 3.17.0
 */
struct TextDocumentInlineValue{
	static constexpr auto Method           = std::string_view("textDocument/inlineValue");
	static constexpr auto ClientCapability = std::string_view("textDocument.inlineValue");
	static constexpr auto ServerCapability = std::string_view("inlineValueProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::InlineValueRegistrationOptions;
	using PartialResult = lsp::TextDocumentInlineValuePartialResult;
	using Params = lsp::InlineValueParams;
	using Result = lsp::TextDocumentInlineValueResult;
};

/*
 * textDocument/linkedEditingRange
 *
 * A request to provide ranges that can be edited together.
 * 
 * @since 3.16.0
 */
struct TextDocumentLinkedEditingRange{
	static constexpr auto Method           = std::string_view("textDocument/linkedEditingRange");
	static constexpr auto ClientCapability = std::string_view("textDocument.linkedEditingRange");
	static constexpr auto ServerCapability = std::string_view("linkedEditingRangeProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::LinkedEditingRangeRegistrationOptions;
	using Params = lsp::LinkedEditingRangeParams;
	using Result = lsp::TextDocumentLinkedEditingRangeResult;
};

/*
 * textDocument/moniker
 *
 * A request to get the moniker of a symbol at a given text document position.
 * The request parameter is of type {@link TextDocumentPositionParams}.
 * The response is of type {@link Moniker Moniker[]} or `null`.
 */
struct TextDocumentMoniker{
	static constexpr auto Method           = std::string_view("textDocument/moniker");
	static constexpr auto ClientCapability = std::string_view("textDocument.moniker");
	static constexpr auto ServerCapability = std::string_view("monikerProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::MonikerRegistrationOptions;
	using PartialResult = lsp::TextDocumentMonikerPartialResult;
	using Params = lsp::MonikerParams;
	using Result = lsp::TextDocumentMonikerResult;
};

/*
 * textDocument/onTypeFormatting
 *
 * A request to format a document on type.
 */
struct TextDocumentOnTypeFormatting{
	static constexpr auto Method           = std::string_view("textDocument/onTypeFormatting");
	static constexpr auto ClientCapability = std::string_view("textDocument.onTypeFormatting");
	static constexpr auto ServerCapability = std::string_view("documentOnTypeFormattingProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentOnTypeFormattingRegistrationOptions;
	using Params = lsp::DocumentOnTypeFormattingParams;
	using Result = lsp::TextDocumentOnTypeFormattingResult;
};

/*
 * textDocument/prepareCallHierarchy
 *
 * A request to result a `CallHierarchyItem` in a document at a given position.
 * Can be used as an input to an incoming or outgoing call hierarchy.
 * 
 * @since 3.16.0
 */
struct TextDocumentPrepareCallHierarchy{
	static constexpr auto Method           = std::string_view("textDocument/prepareCallHierarchy");
	static constexpr auto ClientCapability = std::string_view("textDocument.callHierarchy");
	static constexpr auto ServerCapability = std::string_view("callHierarchyProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::CallHierarchyRegistrationOptions;
	using Params = lsp::CallHierarchyPrepareParams;
	using Result = lsp::TextDocumentPrepareCallHierarchyResult;
};

/*
 * textDocument/prepareRename
 *
 * A request to test and perform the setup necessary for a rename.
 * 
 * @since 3.16 - support for default behavior
 */
struct TextDocumentPrepareRename{
	static constexpr auto Method           = std::string_view("textDocument/prepareRename");
	static constexpr auto ClientCapability = std::string_view("textDocument.rename.prepareSupport");
	static constexpr auto ServerCapability = std::string_view("renameProvider.prepareProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::PrepareRenameParams;
	using Result = lsp::TextDocumentPrepareRenameResult;
};

/*
 * textDocument/prepareTypeHierarchy
 *
 * A request to result a `TypeHierarchyItem` in a document at a given position.
 * Can be used as an input to a subtypes or supertypes type hierarchy.
 * 
 * @since 3.17.0
 */
struct TextDocumentPrepareTypeHierarchy{
	static constexpr auto Method           = std::string_view("textDocument/prepareTypeHierarchy");
	static constexpr auto ClientCapability = std::string_view("textDocument.typeHierarchy");
	static constexpr auto ServerCapability = std::string_view("typeHierarchyProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TypeHierarchyRegistrationOptions;
	using Params = lsp::TypeHierarchyPrepareParams;
	using Result = lsp::TextDocumentPrepareTypeHierarchyResult;
};

/*
 * textDocument/rangeFormatting
 *
 * A request to format a range in a document.
 */
struct TextDocumentRangeFormatting{
	static constexpr auto Method           = std::string_view("textDocument/rangeFormatting");
	static constexpr auto ClientCapability = std::string_view("textDocument.rangeFormatting");
	static constexpr auto ServerCapability = std::string_view("documentRangeFormattingProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentRangeFormattingRegistrationOptions;
	using Params = lsp::DocumentRangeFormattingParams;
	using Result = lsp::TextDocumentRangeFormattingResult;
};

/*
 * textDocument/rangesFormatting
 *
 * A request to format ranges in a document.
 * 
 * @since 3.18.0
 */
struct TextDocumentRangesFormatting{
	static constexpr auto Method           = std::string_view("textDocument/rangesFormatting");
	static constexpr auto ClientCapability = std::string_view("textDocument.rangeFormatting.rangesSupport");
	static constexpr auto ServerCapability = std::string_view("documentRangeFormattingProvider.rangesSupport");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DocumentRangeFormattingRegistrationOptions;
	using Params = lsp::DocumentRangesFormattingParams;
	using Result = lsp::TextDocumentRangesFormattingResult;
};

/*
 * textDocument/references
 *
 * A request to resolve project-wide references for the symbol denoted
 * by the given text document position. The request's parameter is of
 * type {@link ReferenceParams} the response is of type
 * {@link Location Location[]} or a Thenable that resolves to such.
 */
struct TextDocumentReferences{
	static constexpr auto Method           = std::string_view("textDocument/references");
	static constexpr auto ClientCapability = std::string_view("textDocument.references");
	static constexpr auto ServerCapability = std::string_view("referencesProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::ReferenceRegistrationOptions;
	using PartialResult = lsp::TextDocumentReferencesPartialResult;
	using Params = lsp::ReferenceParams;
	using Result = lsp::TextDocumentReferencesResult;
};

/*
 * textDocument/rename
 *
 * A request to rename a symbol.
 */
struct TextDocumentRename{
	static constexpr auto Method           = std::string_view("textDocument/rename");
	static constexpr auto ClientCapability = std::string_view("textDocument.rename");
	static constexpr auto ServerCapability = std::string_view("renameProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::RenameRegistrationOptions;
	using Params = lsp::RenameParams;
	using Result = lsp::TextDocumentRenameResult;
};

/*
 * textDocument/selectionRange
 *
 * A request to provide selection ranges in a document. The request's
 * parameter is of type {@link SelectionRangeParams}, the
 * response is of type {@link SelectionRange SelectionRange[]} or a Thenable
 * that resolves to such.
 */
struct TextDocumentSelectionRange{
	static constexpr auto Method           = std::string_view("textDocument/selectionRange");
	static constexpr auto ClientCapability = std::string_view("textDocument.selectionRange");
	static constexpr auto ServerCapability = std::string_view("selectionRangeProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::SelectionRangeRegistrationOptions;
	using PartialResult = lsp::TextDocumentSelectionRangePartialResult;
	using Params = lsp::SelectionRangeParams;
	using Result = lsp::TextDocumentSelectionRangeResult;
};

/*
 * textDocument/semanticTokens/full
 *
 * @since 3.16.0
 */
struct TextDocumentSemanticTokensFull{
	static constexpr auto Method           = std::string_view("textDocument/semanticTokens/full");
	static constexpr auto ClientCapability = std::string_view("textDocument.semanticTokens");
	static constexpr auto ServerCapability = std::string_view("semanticTokensProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::SemanticTokensRegistrationOptions;
	using PartialResult = lsp::SemanticTokensPartialResult;
	using Params = lsp::SemanticTokensParams;
	using Result = lsp::TextDocumentSemanticTokensFullResult;
};

/*
 * textDocument/semanticTokens/full/delta
 *
 * @since 3.16.0
 */
struct TextDocumentSemanticTokensFullDelta{
	static constexpr auto Method           = std::string_view("textDocument/semanticTokens/full/delta");
	static constexpr auto ClientCapability = std::string_view("textDocument.semanticTokens.requests.full.delta");
	static constexpr auto ServerCapability = std::string_view("semanticTokensProvider.full.delta");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::SemanticTokensRegistrationOptions;
	using PartialResult = lsp::TextDocumentSemanticTokensFullDeltaPartialResult;
	using Params = lsp::SemanticTokensDeltaParams;
	using Result = lsp::TextDocumentSemanticTokensFullDeltaResult;
};

/*
 * textDocument/semanticTokens/range
 *
 * @since 3.16.0
 */
struct TextDocumentSemanticTokensRange{
	static constexpr auto Method           = std::string_view("textDocument/semanticTokens/range");
	static constexpr auto ClientCapability = std::string_view("textDocument.semanticTokens.requests.range");
	static constexpr auto ServerCapability = std::string_view("semanticTokensProvider.range");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::SemanticTokensPartialResult;
	using Params = lsp::SemanticTokensRangeParams;
	using Result = lsp::TextDocumentSemanticTokensRangeResult;
};

/*
 * textDocument/signatureHelp
 */
struct TextDocumentSignatureHelp{
	static constexpr auto Method           = std::string_view("textDocument/signatureHelp");
	static constexpr auto ClientCapability = std::string_view("textDocument.signatureHelp");
	static constexpr auto ServerCapability = std::string_view("signatureHelpProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::SignatureHelpRegistrationOptions;
	using Params = lsp::SignatureHelpParams;
	using Result = lsp::TextDocumentSignatureHelpResult;
};

/*
 * textDocument/typeDefinition
 *
 * A request to resolve the type definition locations of a symbol at a given text
 * document position. The request's parameter is of type {@link TextDocumentPositionParams}
 * the response is of type {@link Definition} or a Thenable that resolves to such.
 */
struct TextDocumentTypeDefinition{
	static constexpr auto Method           = std::string_view("textDocument/typeDefinition");
	static constexpr auto ClientCapability = std::string_view("textDocument.typeDefinition");
	static constexpr auto ServerCapability = std::string_view("typeDefinitionProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TypeDefinitionRegistrationOptions;
	using PartialResult = lsp::TextDocumentTypeDefinitionPartialResult;
	using Params = lsp::TypeDefinitionParams;
	using Result = lsp::TextDocumentTypeDefinitionResult;
};

/*
 * textDocument/willSaveWaitUntil
 *
 * A document will save request is sent from the client to the server before
 * the document is actually saved. The request can return an array of TextEdits
 * which will be applied to the text document before it is saved. Please note that
 * clients might drop results if computing the text edits took too long or if a
 * server constantly fails on this request. This is done to keep the save fast and
 * reliable.
 */
struct TextDocumentWillSaveWaitUntil{
	static constexpr auto Method           = std::string_view("textDocument/willSaveWaitUntil");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization.willSaveWaitUntil");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync.willSaveWaitUntil");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentRegistrationOptions;
	using Params = lsp::WillSaveTextDocumentParams;
	using Result = lsp::TextDocumentWillSaveWaitUntilResult;
};

/*
 * typeHierarchy/subtypes
 *
 * A request to resolve the subtypes for a given `TypeHierarchyItem`.
 * 
 * @since 3.17.0
 */
struct TypeHierarchySubtypes{
	static constexpr auto Method           = std::string_view("typeHierarchy/subtypes");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::TypeHierarchySubtypesPartialResult;
	using Params = lsp::TypeHierarchySubtypesParams;
	using Result = lsp::TypeHierarchySubtypesResult;
};

/*
 * typeHierarchy/supertypes
 *
 * A request to resolve the supertypes for a given `TypeHierarchyItem`.
 * 
 * @since 3.17.0
 */
struct TypeHierarchySupertypes{
	static constexpr auto Method           = std::string_view("typeHierarchy/supertypes");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::TypeHierarchySupertypesPartialResult;
	using Params = lsp::TypeHierarchySupertypesParams;
	using Result = lsp::TypeHierarchySupertypesResult;
};

/*
 * window/showDocument
 *
 * A request to show a document. This request might open an
 * external program depending on the value of the URI to open.
 * For example a request to open `https://code.visualstudio.com/`
 * will very likely open the URI in a WEB browser.
 * 
 * @since 3.16.0
 */
struct WindowShowDocument{
	static constexpr auto Method           = std::string_view("window/showDocument");
	static constexpr auto ClientCapability = std::string_view("window.showDocument.support");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::ShowDocumentParams;
	using Result = lsp::ShowDocumentResult;
};

/*
 * window/showMessageRequest
 *
 * The show message request is sent from the server to the client to show a message
 * and a set of options actions to the user.
 */
struct WindowShowMessageRequest{
	static constexpr auto Method           = std::string_view("window/showMessageRequest");
	static constexpr auto ClientCapability = std::string_view("window.showMessage");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::ShowMessageRequestParams;
	using Result = lsp::WindowShowMessageRequestResult;
};

/*
 * window/workDoneProgress/create
 *
 * The `window/workDoneProgress/create` request is sent from the server to the client to initiate progress
 * reporting from the server.
 */
struct WindowWorkDoneProgressCreate{
	static constexpr auto Method           = std::string_view("window/workDoneProgress/create");
	static constexpr auto ClientCapability = std::string_view("window.workDoneProgress");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::WorkDoneProgressCreateParams;
	using Result = lsp::WindowWorkDoneProgressCreateResult;
};

/*
 * workspace/applyEdit
 *
 * A request sent from the server to the client to modified certain resources.
 */
struct WorkspaceApplyEdit{
	static constexpr auto Method           = std::string_view("workspace/applyEdit");
	static constexpr auto ClientCapability = std::string_view("workspace.applyEdit");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::ApplyWorkspaceEditParams;
	using Result = lsp::ApplyWorkspaceEditResult;
};

/*
 * workspace/codeLens/refresh
 *
 * A request to refresh all code actions
 * 
 * @since 3.16.0
 */
struct WorkspaceCodeLensRefresh{
	static constexpr auto Method           = std::string_view("workspace/codeLens/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.codeLens");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceCodeLensRefreshResult;
};

/*
 * workspace/configuration
 *
 * The 'workspace/configuration' request is sent from the server to the client to fetch a certain
 * configuration setting.
 * 
 * This pull model replaces the old push model were the client signaled configuration change via an
 * event. If the server still needs to react to configuration changes (since the server caches the
 * result of `workspace/configuration` requests) the server should register for an empty configuration
 * change event and empty the cache if such an event is received.
 */
struct WorkspaceConfiguration{
	static constexpr auto Method           = std::string_view("workspace/configuration");
	static constexpr auto ClientCapability = std::string_view("workspace.configuration");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::ConfigurationParams;
	using Result = lsp::WorkspaceConfigurationResult;
};

/*
 * workspace/diagnostic
 *
 * The workspace diagnostic request definition.
 * 
 * @since 3.17.0
 */
struct WorkspaceDiagnostic{
	static constexpr auto Method           = std::string_view("workspace/diagnostic");
	static constexpr auto ClientCapability = std::string_view("workspace.diagnostics");
	static constexpr auto ServerCapability = std::string_view("diagnosticProvider.workspaceDiagnostics");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using PartialResult = lsp::WorkspaceDiagnosticReportPartialResult;
	using ErrorData = lsp::DiagnosticServerCancellationData;
	using Params = lsp::WorkspaceDiagnosticParams;
	using Result = lsp::WorkspaceDiagnosticReport;
};

/*
 * workspace/diagnostic/refresh
 *
 * The diagnostic refresh request definition.
 * 
 * @since 3.17.0
 */
struct WorkspaceDiagnosticRefresh{
	static constexpr auto Method           = std::string_view("workspace/diagnostic/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.diagnostics.refreshSupport");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceDiagnosticRefreshResult;
};

/*
 * workspace/executeCommand
 *
 * A request send from the client to the server to execute a command. The request might return
 * a workspace edit which the client will apply to the workspace.
 */
struct WorkspaceExecuteCommand{
	static constexpr auto Method           = std::string_view("workspace/executeCommand");
	static constexpr auto ClientCapability = std::string_view("workspace.executeCommand");
	static constexpr auto ServerCapability = std::string_view("executeCommandProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::ExecuteCommandRegistrationOptions;
	using Params = lsp::ExecuteCommandParams;
	using Result = lsp::WorkspaceExecuteCommandResult;
};

/*
 * workspace/foldingRange/refresh
 *
 * A request to refresh the folding ranges in a document.
 * 
 * @since 3.18.0
 */
struct WorkspaceFoldingRangeRefresh{
	static constexpr auto Method           = std::string_view("workspace/foldingRange/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.foldingRange.refreshSupport");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceFoldingRangeRefreshResult;
};

/*
 * workspace/inlayHint/refresh
 *
 * @since 3.17.0
 */
struct WorkspaceInlayHintRefresh{
	static constexpr auto Method           = std::string_view("workspace/inlayHint/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.inlayHint.refreshSupport");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceInlayHintRefreshResult;
};

/*
 * workspace/inlineValue/refresh
 *
 * @since 3.17.0
 */
struct WorkspaceInlineValueRefresh{
	static constexpr auto Method           = std::string_view("workspace/inlineValue/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.inlineValue.refreshSupport");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceInlineValueRefreshResult;
};

/*
 * workspace/semanticTokens/refresh
 *
 * @since 3.16.0
 */
struct WorkspaceSemanticTokensRefresh{
	static constexpr auto Method           = std::string_view("workspace/semanticTokens/refresh");
	static constexpr auto ClientCapability = std::string_view("workspace.semanticTokens.refreshSupport");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceSemanticTokensRefreshResult;
};

/*
 * workspace/symbol
 *
 * A request to list project-wide symbols matching the query string given
 * by the {@link WorkspaceSymbolParams}. The response is
 * of type {@link SymbolInformation SymbolInformation[]} or a Thenable that
 * resolves to such.
 * 
 * @since 3.17.0 - support for WorkspaceSymbol in the returned data. Clients
 *  need to advertise support for WorkspaceSymbols via the client capability
 *  `workspace.symbol.resolveSupport`.
 */
struct WorkspaceSymbol{
	static constexpr auto Method           = std::string_view("workspace/symbol");
	static constexpr auto ClientCapability = std::string_view("workspace.symbol");
	static constexpr auto ServerCapability = std::string_view("workspaceSymbolProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::WorkspaceSymbolRegistrationOptions;
	using PartialResult = lsp::WorkspaceSymbolPartialResult;
	using Params = lsp::WorkspaceSymbolParams;
	using Result = lsp::WorkspaceSymbolResult;
};

/*
 * workspace/textDocumentContent
 *
 * The `workspace/textDocumentContent` request is sent from the client to the
 * server to request the content of a text document.
 * 
 * @since 3.18.0
 */
struct WorkspaceTextDocumentContent{
	static constexpr auto Method           = std::string_view("workspace/textDocumentContent");
	static constexpr auto ClientCapability = std::string_view("workspace.textDocumentContent");
	static constexpr auto ServerCapability = std::string_view("workspace.textDocumentContent");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentContentRegistrationOptions;
	using Params = lsp::TextDocumentContentParams;
	using Result = lsp::TextDocumentContentResult;
};

/*
 * workspace/textDocumentContent/refresh
 *
 * The `workspace/textDocumentContent` request is sent from the server to the client to refresh
 * the content of a specific text document.
 * 
 * @since 3.18.0
 */
struct WorkspaceTextDocumentContentRefresh{
	static constexpr auto Method           = std::string_view("workspace/textDocumentContent/refresh");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::TextDocumentContentRefreshParams;
	using Result = lsp::WorkspaceTextDocumentContentRefreshResult;
};

/*
 * workspace/willCreateFiles
 *
 * The will create files request is sent from the client to the server before files are actually
 * created as long as the creation is triggered from within the client.
 * 
 * The request can return a `WorkspaceEdit` which will be applied to workspace before the
 * files are created. Hence the `WorkspaceEdit` can not manipulate the content of the file
 * to be created.
 * 
 * @since 3.16.0
 */
struct WorkspaceWillCreateFiles{
	static constexpr auto Method           = std::string_view("workspace/willCreateFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.willCreate");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.willCreate");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::CreateFilesParams;
	using Result = lsp::WorkspaceWillCreateFilesResult;
};

/*
 * workspace/willDeleteFiles
 *
 * The did delete files notification is sent from the client to the server when
 * files were deleted from within the client.
 * 
 * @since 3.16.0
 */
struct WorkspaceWillDeleteFiles{
	static constexpr auto Method           = std::string_view("workspace/willDeleteFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.willDelete");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.willDelete");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::DeleteFilesParams;
	using Result = lsp::WorkspaceWillDeleteFilesResult;
};

/*
 * workspace/willRenameFiles
 *
 * The will rename files request is sent from the client to the server before files are actually
 * renamed as long as the rename is triggered from within the client.
 * 
 * @since 3.16.0
 */
struct WorkspaceWillRenameFiles{
	static constexpr auto Method           = std::string_view("workspace/willRenameFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.willRename");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.willRename");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::RenameFilesParams;
	using Result = lsp::WorkspaceWillRenameFilesResult;
};

/*
 * workspace/workspaceFolders
 *
 * The `workspace/workspaceFolders` is sent from the server to the client to fetch the open workspace folders.
 */
struct WorkspaceWorkspaceFolders{
	static constexpr auto Method           = std::string_view("workspace/workspaceFolders");
	static constexpr auto ClientCapability = std::string_view("workspace.workspaceFolders");
	static constexpr auto ServerCapability = std::string_view("workspace.workspaceFolders");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Result = lsp::WorkspaceWorkspaceFoldersResult;
};

/*
 * workspaceSymbol/resolve
 *
 * A request to resolve the range inside the workspace
 * symbol's location.
 * 
 * @since 3.17.0
 */
struct WorkspaceSymbolResolve{
	static constexpr auto Method           = std::string_view("workspaceSymbol/resolve");
	static constexpr auto ClientCapability = std::string_view("workspace.symbol.resolveSupport");
	static constexpr auto ServerCapability = std::string_view("workspaceSymbolProvider.resolveProvider");
	static constexpr auto Kind             = MessageKind::Request;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::WorkspaceSymbol;
	using Result = lsp::WorkspaceSymbol;
};

} // namespace requests

/*
 * Notification messages
 */

namespace notifications{

/*
 * $/cancelRequest
 */
struct CancelRequest{
	static constexpr auto Method           = std::string_view("$/cancelRequest");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::Bidirectional;

	using Params = lsp::CancelParams;
};

/*
 * $/logTrace
 */
struct LogTrace{
	static constexpr auto Method           = std::string_view("$/logTrace");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::LogTraceParams;
};

/*
 * $/progress
 */
struct Progress{
	static constexpr auto Method           = std::string_view("$/progress");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::Bidirectional;

	using Params = lsp::ProgressParams;
};

/*
 * $/setTrace
 */
struct SetTrace{
	static constexpr auto Method           = std::string_view("$/setTrace");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::SetTraceParams;
};

/*
 * exit
 *
 * The exit event is sent from the client to the server to
 * ask the server to exit its process.
 */
struct Exit{
	static constexpr auto Method           = std::string_view("exit");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;
};

/*
 * initialized
 *
 * The initialized notification is sent from the client to the
 * server after the client is fully initialized and the server
 * is allowed to send requests from the server to the client.
 */
struct Initialized{
	static constexpr auto Method           = std::string_view("initialized");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::InitializedParams;
};

/*
 * notebookDocument/didChange
 */
struct NotebookDocumentDidChange{
	static constexpr auto Method           = std::string_view("notebookDocument/didChange");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::NotebookDocumentSyncRegistrationOptions;
	using Params = lsp::DidChangeNotebookDocumentParams;
};

/*
 * notebookDocument/didClose
 *
 * A notification sent when a notebook closes.
 * 
 * @since 3.17.0
 */
struct NotebookDocumentDidClose{
	static constexpr auto Method           = std::string_view("notebookDocument/didClose");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::NotebookDocumentSyncRegistrationOptions;
	using Params = lsp::DidCloseNotebookDocumentParams;
};

/*
 * notebookDocument/didOpen
 *
 * A notification sent when a notebook opens.
 * 
 * @since 3.17.0
 */
struct NotebookDocumentDidOpen{
	static constexpr auto Method           = std::string_view("notebookDocument/didOpen");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::NotebookDocumentSyncRegistrationOptions;
	using Params = lsp::DidOpenNotebookDocumentParams;
};

/*
 * notebookDocument/didSave
 *
 * A notification sent when a notebook document is saved.
 * 
 * @since 3.17.0
 */
struct NotebookDocumentDidSave{
	static constexpr auto Method           = std::string_view("notebookDocument/didSave");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::NotebookDocumentSyncRegistrationOptions;
	using Params = lsp::DidSaveNotebookDocumentParams;
};

/*
 * telemetry/event
 *
 * The telemetry event notification is sent from the server to the client to ask
 * the client to log telemetry data.
 */
struct TelemetryEvent{
	static constexpr auto Method           = std::string_view("telemetry/event");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::LSPAny;
};

/*
 * textDocument/didChange
 *
 * The document change notification is sent from the client to the server to signal
 * changes to a text document.
 */
struct TextDocumentDidChange{
	static constexpr auto Method           = std::string_view("textDocument/didChange");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentChangeRegistrationOptions;
	using Params = lsp::DidChangeTextDocumentParams;
};

/*
 * textDocument/didClose
 *
 * The document close notification is sent from the client to the server when
 * the document got closed in the client. The document's truth now exists where
 * the document's uri points to (e.g. if the document's uri is a file uri the
 * truth now exists on disk). As with the open notification the close notification
 * is about managing the document's content. Receiving a close notification
 * doesn't mean that the document was open in an editor before. A close
 * notification requires a previous open notification to be sent.
 */
struct TextDocumentDidClose{
	static constexpr auto Method           = std::string_view("textDocument/didClose");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync.openClose");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentRegistrationOptions;
	using Params = lsp::DidCloseTextDocumentParams;
};

/*
 * textDocument/didOpen
 *
 * The document open notification is sent from the client to the server to signal
 * newly opened text documents. The document's truth is now managed by the client
 * and the server must not try to read the document's truth using the document's
 * uri. Open in this sense means it is managed by the client. It doesn't necessarily
 * mean that its content is presented in an editor. An open notification must not
 * be sent more than once without a corresponding close notification send before.
 * This means open and close notification must be balanced and the max open count
 * is one.
 */
struct TextDocumentDidOpen{
	static constexpr auto Method           = std::string_view("textDocument/didOpen");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync.openClose");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentRegistrationOptions;
	using Params = lsp::DidOpenTextDocumentParams;
};

/*
 * textDocument/didSave
 *
 * The document save notification is sent from the client to the server when
 * the document got saved in the client.
 */
struct TextDocumentDidSave{
	static constexpr auto Method           = std::string_view("textDocument/didSave");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization.didSave");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync.save");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentSaveRegistrationOptions;
	using Params = lsp::DidSaveTextDocumentParams;
};

/*
 * textDocument/publishDiagnostics
 *
 * Diagnostics notification are sent from the server to the client to signal
 * results of validation runs.
 */
struct TextDocumentPublishDiagnostics{
	static constexpr auto Method           = std::string_view("textDocument/publishDiagnostics");
	static constexpr auto ClientCapability = std::string_view("textDocument.publishDiagnostics");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::PublishDiagnosticsParams;
};

/*
 * textDocument/willSave
 *
 * A document will save notification is sent from the client to the server before
 * the document is actually saved.
 */
struct TextDocumentWillSave{
	static constexpr auto Method           = std::string_view("textDocument/willSave");
	static constexpr auto ClientCapability = std::string_view("textDocument.synchronization.willSave");
	static constexpr auto ServerCapability = std::string_view("textDocumentSync.willSave");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::TextDocumentRegistrationOptions;
	using Params = lsp::WillSaveTextDocumentParams;
};

/*
 * window/logMessage
 *
 * The log message notification is sent from the server to the client to ask
 * the client to log a particular message.
 */
struct WindowLogMessage{
	static constexpr auto Method           = std::string_view("window/logMessage");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::LogMessageParams;
};

/*
 * window/showMessage
 *
 * The show message notification is sent from a server to a client to ask
 * the client to display a particular message in the user interface.
 */
struct WindowShowMessage{
	static constexpr auto Method           = std::string_view("window/showMessage");
	static constexpr auto ClientCapability = std::string_view("window.showMessage");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ServerToClient;

	using Params = lsp::ShowMessageParams;
};

/*
 * window/workDoneProgress/cancel
 *
 * The `window/workDoneProgress/cancel` notification is sent from  the client to the server to cancel a progress
 * initiated on the server side.
 */
struct WindowWorkDoneProgressCancel{
	static constexpr auto Method           = std::string_view("window/workDoneProgress/cancel");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::WorkDoneProgressCancelParams;
};

/*
 * workspace/didChangeConfiguration
 *
 * The configuration change notification is sent from the client to the server
 * when the client's configuration has changed. The notification contains
 * the changed configuration as defined by the language client.
 */
struct WorkspaceDidChangeConfiguration{
	static constexpr auto Method           = std::string_view("workspace/didChangeConfiguration");
	static constexpr auto ClientCapability = std::string_view("workspace.didChangeConfiguration");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DidChangeConfigurationRegistrationOptions;
	using Params = lsp::DidChangeConfigurationParams;
};

/*
 * workspace/didChangeWatchedFiles
 *
 * The watched files notification is sent from the client to the server when
 * the client detects changes to file watched by the language client.
 */
struct WorkspaceDidChangeWatchedFiles{
	static constexpr auto Method           = std::string_view("workspace/didChangeWatchedFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.didChangeWatchedFiles");
	static constexpr auto ServerCapability = std::string_view("");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::DidChangeWatchedFilesRegistrationOptions;
	using Params = lsp::DidChangeWatchedFilesParams;
};

/*
 * workspace/didChangeWorkspaceFolders
 *
 * The `workspace/didChangeWorkspaceFolders` notification is sent from the client to the server when the workspace
 * folder configuration changes.
 */
struct WorkspaceDidChangeWorkspaceFolders{
	static constexpr auto Method           = std::string_view("workspace/didChangeWorkspaceFolders");
	static constexpr auto ClientCapability = std::string_view("");
	static constexpr auto ServerCapability = std::string_view("workspace.workspaceFolders.changeNotifications");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using Params = lsp::DidChangeWorkspaceFoldersParams;
};

/*
 * workspace/didCreateFiles
 *
 * The did create files notification is sent from the client to the server when
 * files were created from within the client.
 * 
 * @since 3.16.0
 */
struct WorkspaceDidCreateFiles{
	static constexpr auto Method           = std::string_view("workspace/didCreateFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.didCreate");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.didCreate");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::CreateFilesParams;
};

/*
 * workspace/didDeleteFiles
 *
 * The will delete files request is sent from the client to the server before files are actually
 * deleted as long as the deletion is triggered from within the client.
 * 
 * @since 3.16.0
 */
struct WorkspaceDidDeleteFiles{
	static constexpr auto Method           = std::string_view("workspace/didDeleteFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.didDelete");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.didDelete");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::DeleteFilesParams;
};

/*
 * workspace/didRenameFiles
 *
 * The did rename files notification is sent from the client to the server when
 * files were renamed from within the client.
 * 
 * @since 3.16.0
 */
struct WorkspaceDidRenameFiles{
	static constexpr auto Method           = std::string_view("workspace/didRenameFiles");
	static constexpr auto ClientCapability = std::string_view("workspace.fileOperations.didRename");
	static constexpr auto ServerCapability = std::string_view("workspace.fileOperations.didRename");
	static constexpr auto Kind             = MessageKind::Notification;
	static constexpr auto Direction        = MessageDirection::ClientToServer;

	using RegistrationOptions = lsp::FileOperationRegistrationOptions;
	using Params = lsp::RenameFilesParams;
};

} // namespace notifications

} // namespace lsp
