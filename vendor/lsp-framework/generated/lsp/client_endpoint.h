/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#pragma once

#include <lsp/endpoint_base.h>
#include <lsp/messages.h>

namespace lsp{

class ClientEndpoint : public ClientEndpointBase{
public:
	ClientEndpoint(io::Stream& stream);

	/*
	 * Outgoing requests
	 */

	[[nodiscard]] auto callHierarchyIncomingCalls(const CallHierarchyIncomingCallsParams& params) -> RequestResult<CallHierarchyIncomingCallsResult>;
	[[nodiscard]] auto callHierarchyOutgoingCalls(const CallHierarchyOutgoingCallsParams& params) -> RequestResult<CallHierarchyOutgoingCallsResult>;
	[[nodiscard]] auto codeActionResolve(const CodeAction& params) -> RequestResult<CodeAction>;
	[[nodiscard]] auto codeLensResolve(const CodeLens& params) -> RequestResult<CodeLens>;
	[[nodiscard]] auto completionItemResolve(const CompletionItem& params) -> RequestResult<CompletionItem>;
	[[nodiscard]] auto documentLinkResolve(const DocumentLink& params) -> RequestResult<DocumentLink>;
	[[nodiscard]] auto initialize(const InitializeParams& params) -> RequestResult<InitializeResult>;
	[[nodiscard]] auto inlayHintResolve(const InlayHint& params) -> RequestResult<InlayHint>;
	[[nodiscard]] auto shutdown() -> RequestResult<ShutdownResult>;
	[[nodiscard]] auto textDocumentCodeAction(const CodeActionParams& params) -> RequestResult<TextDocumentCodeActionResult>;
	[[nodiscard]] auto textDocumentCodeLens(const CodeLensParams& params) -> RequestResult<TextDocumentCodeLensResult>;
	[[nodiscard]] auto textDocumentColorPresentation(const ColorPresentationParams& params) -> RequestResult<TextDocumentColorPresentationResult>;
	[[nodiscard]] auto textDocumentCompletion(const CompletionParams& params) -> RequestResult<TextDocumentCompletionResult>;
	[[nodiscard]] auto textDocumentDeclaration(const DeclarationParams& params) -> RequestResult<TextDocumentDeclarationResult>;
	[[nodiscard]] auto textDocumentDefinition(const DefinitionParams& params) -> RequestResult<TextDocumentDefinitionResult>;
	[[nodiscard]] auto textDocumentDiagnostic(const DocumentDiagnosticParams& params) -> RequestResult<DocumentDiagnosticReport>;
	[[nodiscard]] auto textDocumentDocumentColor(const DocumentColorParams& params) -> RequestResult<TextDocumentDocumentColorResult>;
	[[nodiscard]] auto textDocumentDocumentHighlight(const DocumentHighlightParams& params) -> RequestResult<TextDocumentDocumentHighlightResult>;
	[[nodiscard]] auto textDocumentDocumentLink(const DocumentLinkParams& params) -> RequestResult<TextDocumentDocumentLinkResult>;
	[[nodiscard]] auto textDocumentDocumentSymbol(const DocumentSymbolParams& params) -> RequestResult<TextDocumentDocumentSymbolResult>;
	[[nodiscard]] auto textDocumentFoldingRange(const FoldingRangeParams& params) -> RequestResult<TextDocumentFoldingRangeResult>;
	[[nodiscard]] auto textDocumentFormatting(const DocumentFormattingParams& params) -> RequestResult<TextDocumentFormattingResult>;
	[[nodiscard]] auto textDocumentHover(const HoverParams& params) -> RequestResult<TextDocumentHoverResult>;
	[[nodiscard]] auto textDocumentImplementation(const ImplementationParams& params) -> RequestResult<TextDocumentImplementationResult>;
	[[nodiscard]] auto textDocumentInlayHint(const InlayHintParams& params) -> RequestResult<TextDocumentInlayHintResult>;
	[[nodiscard]] auto textDocumentInlineCompletion(const InlineCompletionParams& params) -> RequestResult<TextDocumentInlineCompletionResult>;
	[[nodiscard]] auto textDocumentInlineValue(const InlineValueParams& params) -> RequestResult<TextDocumentInlineValueResult>;
	[[nodiscard]] auto textDocumentLinkedEditingRange(const LinkedEditingRangeParams& params) -> RequestResult<TextDocumentLinkedEditingRangeResult>;
	[[nodiscard]] auto textDocumentMoniker(const MonikerParams& params) -> RequestResult<TextDocumentMonikerResult>;
	[[nodiscard]] auto textDocumentOnTypeFormatting(const DocumentOnTypeFormattingParams& params) -> RequestResult<TextDocumentOnTypeFormattingResult>;
	[[nodiscard]] auto textDocumentPrepareCallHierarchy(const CallHierarchyPrepareParams& params) -> RequestResult<TextDocumentPrepareCallHierarchyResult>;
	[[nodiscard]] auto textDocumentPrepareRename(const PrepareRenameParams& params) -> RequestResult<TextDocumentPrepareRenameResult>;
	[[nodiscard]] auto textDocumentPrepareTypeHierarchy(const TypeHierarchyPrepareParams& params) -> RequestResult<TextDocumentPrepareTypeHierarchyResult>;
	[[nodiscard]] auto textDocumentRangeFormatting(const DocumentRangeFormattingParams& params) -> RequestResult<TextDocumentRangeFormattingResult>;
	[[nodiscard]] auto textDocumentRangesFormatting(const DocumentRangesFormattingParams& params) -> RequestResult<TextDocumentRangesFormattingResult>;
	[[nodiscard]] auto textDocumentReferences(const ReferenceParams& params) -> RequestResult<TextDocumentReferencesResult>;
	[[nodiscard]] auto textDocumentRename(const RenameParams& params) -> RequestResult<TextDocumentRenameResult>;
	[[nodiscard]] auto textDocumentSelectionRange(const SelectionRangeParams& params) -> RequestResult<TextDocumentSelectionRangeResult>;
	[[nodiscard]] auto textDocumentSemanticTokensFull(const SemanticTokensParams& params) -> RequestResult<TextDocumentSemanticTokensFullResult>;
	[[nodiscard]] auto textDocumentSemanticTokensFullDelta(const SemanticTokensDeltaParams& params) -> RequestResult<TextDocumentSemanticTokensFullDeltaResult>;
	[[nodiscard]] auto textDocumentSemanticTokensRange(const SemanticTokensRangeParams& params) -> RequestResult<TextDocumentSemanticTokensRangeResult>;
	[[nodiscard]] auto textDocumentSignatureHelp(const SignatureHelpParams& params) -> RequestResult<TextDocumentSignatureHelpResult>;
	[[nodiscard]] auto textDocumentTypeDefinition(const TypeDefinitionParams& params) -> RequestResult<TextDocumentTypeDefinitionResult>;
	[[nodiscard]] auto textDocumentWillSaveWaitUntil(const WillSaveTextDocumentParams& params) -> RequestResult<TextDocumentWillSaveWaitUntilResult>;
	[[nodiscard]] auto typeHierarchySubtypes(const TypeHierarchySubtypesParams& params) -> RequestResult<TypeHierarchySubtypesResult>;
	[[nodiscard]] auto typeHierarchySupertypes(const TypeHierarchySupertypesParams& params) -> RequestResult<TypeHierarchySupertypesResult>;
	[[nodiscard]] auto workspaceDiagnostic(const WorkspaceDiagnosticParams& params) -> RequestResult<WorkspaceDiagnosticReport>;
	[[nodiscard]] auto workspaceExecuteCommand(const ExecuteCommandParams& params) -> RequestResult<WorkspaceExecuteCommandResult>;
	[[nodiscard]] auto workspaceSymbol(const WorkspaceSymbolParams& params) -> RequestResult<WorkspaceSymbolResult>;
	[[nodiscard]] auto workspaceTextDocumentContent(const TextDocumentContentParams& params) -> RequestResult<TextDocumentContentResult>;
	[[nodiscard]] auto workspaceWillCreateFiles(const CreateFilesParams& params) -> RequestResult<WorkspaceWillCreateFilesResult>;
	[[nodiscard]] auto workspaceWillDeleteFiles(const DeleteFilesParams& params) -> RequestResult<WorkspaceWillDeleteFilesResult>;
	[[nodiscard]] auto workspaceWillRenameFiles(const RenameFilesParams& params) -> RequestResult<WorkspaceWillRenameFilesResult>;
	[[nodiscard]] auto workspaceSymbolResolve(const WorkspaceSymbol& params) -> RequestResult<WorkspaceSymbol>;

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto callHierarchyIncomingCalls(const CallHierarchyIncomingCallsParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::CallHierarchyIncomingCalls>(*this);
		return messageHandler().sendRequest<requests::CallHierarchyIncomingCalls>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto callHierarchyOutgoingCalls(const CallHierarchyOutgoingCallsParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::CallHierarchyOutgoingCalls>(*this);
		return messageHandler().sendRequest<requests::CallHierarchyOutgoingCalls>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto codeActionResolve(const CodeAction& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::CodeActionResolve>(*this);
		return messageHandler().sendRequest<requests::CodeActionResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto codeLensResolve(const CodeLens& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::CodeLensResolve>(*this);
		return messageHandler().sendRequest<requests::CodeLensResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto completionItemResolve(const CompletionItem& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::CompletionItemResolve>(*this);
		return messageHandler().sendRequest<requests::CompletionItemResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto documentLinkResolve(const DocumentLink& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::DocumentLinkResolve>(*this);
		return messageHandler().sendRequest<requests::DocumentLinkResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto initialize(const InitializeParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::Initialize>(*this);
		return messageHandler().sendRequest<requests::Initialize>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto inlayHintResolve(const InlayHint& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::InlayHintResolve>(*this);
		return messageHandler().sendRequest<requests::InlayHintResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto shutdown(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::Shutdown>(*this);
		return messageHandler().sendRequest<requests::Shutdown>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentCodeAction(const CodeActionParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentCodeAction>(*this);
		return messageHandler().sendRequest<requests::TextDocumentCodeAction>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentCodeLens(const CodeLensParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentCodeLens>(*this);
		return messageHandler().sendRequest<requests::TextDocumentCodeLens>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentColorPresentation(const ColorPresentationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentColorPresentation>(*this);
		return messageHandler().sendRequest<requests::TextDocumentColorPresentation>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentCompletion(const CompletionParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentCompletion>(*this);
		return messageHandler().sendRequest<requests::TextDocumentCompletion>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDeclaration(const DeclarationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDeclaration>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDeclaration>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDefinition(const DefinitionParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDefinition>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDefinition>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDiagnostic(const DocumentDiagnosticParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDiagnostic>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDiagnostic>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDocumentColor(const DocumentColorParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDocumentColor>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDocumentColor>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDocumentHighlight(const DocumentHighlightParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDocumentHighlight>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDocumentHighlight>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDocumentLink(const DocumentLinkParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDocumentLink>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDocumentLink>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentDocumentSymbol(const DocumentSymbolParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentDocumentSymbol>(*this);
		return messageHandler().sendRequest<requests::TextDocumentDocumentSymbol>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentFoldingRange(const FoldingRangeParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentFoldingRange>(*this);
		return messageHandler().sendRequest<requests::TextDocumentFoldingRange>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentFormatting(const DocumentFormattingParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentFormatting>(*this);
		return messageHandler().sendRequest<requests::TextDocumentFormatting>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentHover(const HoverParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentHover>(*this);
		return messageHandler().sendRequest<requests::TextDocumentHover>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentImplementation(const ImplementationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentImplementation>(*this);
		return messageHandler().sendRequest<requests::TextDocumentImplementation>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentInlayHint(const InlayHintParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentInlayHint>(*this);
		return messageHandler().sendRequest<requests::TextDocumentInlayHint>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentInlineCompletion(const InlineCompletionParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentInlineCompletion>(*this);
		return messageHandler().sendRequest<requests::TextDocumentInlineCompletion>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentInlineValue(const InlineValueParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentInlineValue>(*this);
		return messageHandler().sendRequest<requests::TextDocumentInlineValue>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentLinkedEditingRange(const LinkedEditingRangeParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentLinkedEditingRange>(*this);
		return messageHandler().sendRequest<requests::TextDocumentLinkedEditingRange>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentMoniker(const MonikerParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentMoniker>(*this);
		return messageHandler().sendRequest<requests::TextDocumentMoniker>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentOnTypeFormatting(const DocumentOnTypeFormattingParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentOnTypeFormatting>(*this);
		return messageHandler().sendRequest<requests::TextDocumentOnTypeFormatting>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentPrepareCallHierarchy(const CallHierarchyPrepareParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentPrepareCallHierarchy>(*this);
		return messageHandler().sendRequest<requests::TextDocumentPrepareCallHierarchy>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentPrepareRename(const PrepareRenameParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentPrepareRename>(*this);
		return messageHandler().sendRequest<requests::TextDocumentPrepareRename>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentPrepareTypeHierarchy(const TypeHierarchyPrepareParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentPrepareTypeHierarchy>(*this);
		return messageHandler().sendRequest<requests::TextDocumentPrepareTypeHierarchy>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentRangeFormatting(const DocumentRangeFormattingParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentRangeFormatting>(*this);
		return messageHandler().sendRequest<requests::TextDocumentRangeFormatting>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentRangesFormatting(const DocumentRangesFormattingParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentRangesFormatting>(*this);
		return messageHandler().sendRequest<requests::TextDocumentRangesFormatting>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentReferences(const ReferenceParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentReferences>(*this);
		return messageHandler().sendRequest<requests::TextDocumentReferences>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentRename(const RenameParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentRename>(*this);
		return messageHandler().sendRequest<requests::TextDocumentRename>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentSelectionRange(const SelectionRangeParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentSelectionRange>(*this);
		return messageHandler().sendRequest<requests::TextDocumentSelectionRange>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentSemanticTokensFull(const SemanticTokensParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentSemanticTokensFull>(*this);
		return messageHandler().sendRequest<requests::TextDocumentSemanticTokensFull>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentSemanticTokensFullDelta(const SemanticTokensDeltaParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentSemanticTokensFullDelta>(*this);
		return messageHandler().sendRequest<requests::TextDocumentSemanticTokensFullDelta>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentSemanticTokensRange(const SemanticTokensRangeParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentSemanticTokensRange>(*this);
		return messageHandler().sendRequest<requests::TextDocumentSemanticTokensRange>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentSignatureHelp(const SignatureHelpParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentSignatureHelp>(*this);
		return messageHandler().sendRequest<requests::TextDocumentSignatureHelp>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentTypeDefinition(const TypeDefinitionParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentTypeDefinition>(*this);
		return messageHandler().sendRequest<requests::TextDocumentTypeDefinition>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto textDocumentWillSaveWaitUntil(const WillSaveTextDocumentParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TextDocumentWillSaveWaitUntil>(*this);
		return messageHandler().sendRequest<requests::TextDocumentWillSaveWaitUntil>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto typeHierarchySubtypes(const TypeHierarchySubtypesParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TypeHierarchySubtypes>(*this);
		return messageHandler().sendRequest<requests::TypeHierarchySubtypes>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto typeHierarchySupertypes(const TypeHierarchySupertypesParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::TypeHierarchySupertypes>(*this);
		return messageHandler().sendRequest<requests::TypeHierarchySupertypes>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceDiagnostic(const WorkspaceDiagnosticParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceDiagnostic>(*this);
		return messageHandler().sendRequest<requests::WorkspaceDiagnostic>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceExecuteCommand(const ExecuteCommandParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceExecuteCommand>(*this);
		return messageHandler().sendRequest<requests::WorkspaceExecuteCommand>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceSymbol(const WorkspaceSymbolParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceSymbol>(*this);
		return messageHandler().sendRequest<requests::WorkspaceSymbol>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceTextDocumentContent(const TextDocumentContentParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceTextDocumentContent>(*this);
		return messageHandler().sendRequest<requests::WorkspaceTextDocumentContent>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceWillCreateFiles(const CreateFilesParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceWillCreateFiles>(*this);
		return messageHandler().sendRequest<requests::WorkspaceWillCreateFiles>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceWillDeleteFiles(const DeleteFilesParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceWillDeleteFiles>(*this);
		return messageHandler().sendRequest<requests::WorkspaceWillDeleteFiles>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceWillRenameFiles(const RenameFilesParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceWillRenameFiles>(*this);
		return messageHandler().sendRequest<requests::WorkspaceWillRenameFiles>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceSymbolResolve(const WorkspaceSymbol& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceSymbolResolve>(*this);
		return messageHandler().sendRequest<requests::WorkspaceSymbolResolve>(params, std::forward<F>(then), std::forward<E>(error));
	}

	/*
	 * Outgoing notifications
	 */

	void cancelRequest(const CancelParams& params);
	void progress(const ProgressParams& params);
	void setTrace(const SetTraceParams& params);
	void exit();
	void initialized(const InitializedParams& params);
	void notebookDocumentDidChange(const DidChangeNotebookDocumentParams& params);
	void notebookDocumentDidClose(const DidCloseNotebookDocumentParams& params);
	void notebookDocumentDidOpen(const DidOpenNotebookDocumentParams& params);
	void notebookDocumentDidSave(const DidSaveNotebookDocumentParams& params);
	void textDocumentDidChange(const DidChangeTextDocumentParams& params);
	void textDocumentDidClose(const DidCloseTextDocumentParams& params);
	void textDocumentDidOpen(const DidOpenTextDocumentParams& params);
	void textDocumentDidSave(const DidSaveTextDocumentParams& params);
	void textDocumentWillSave(const WillSaveTextDocumentParams& params);
	void windowWorkDoneProgressCancel(const WorkDoneProgressCancelParams& params);
	void workspaceDidChangeConfiguration(const DidChangeConfigurationParams& params);
	void workspaceDidChangeWatchedFiles(const DidChangeWatchedFilesParams& params);
	void workspaceDidChangeWorkspaceFolders(const DidChangeWorkspaceFoldersParams& params);
	void workspaceDidCreateFiles(const CreateFilesParams& params);
	void workspaceDidDeleteFiles(const DeleteFilesParams& params);
	void workspaceDidRenameFiles(const RenameFilesParams& params);
	

	/*
	 * Incoming requests
	 */

	template<typename F>
	auto onClientRegisterCapability(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::ClientRegisterCapability>(
			[this, callback = std::forward<F>(callback)](RegistrationParams&& params) mutable
			{
				const auto hook = messageHook<requests::ClientRegisterCapability>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onClientUnregisterCapability(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::ClientUnregisterCapability>(
			[this, callback = std::forward<F>(callback)](UnregistrationParams&& params) mutable
			{
				const auto hook = messageHook<requests::ClientUnregisterCapability>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowShowDocument(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WindowShowDocument>(
			[this, callback = std::forward<F>(callback)](ShowDocumentParams&& params) mutable
			{
				const auto hook = messageHook<requests::WindowShowDocument>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowShowMessageRequest(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WindowShowMessageRequest>(
			[this, callback = std::forward<F>(callback)](ShowMessageRequestParams&& params) mutable
			{
				const auto hook = messageHook<requests::WindowShowMessageRequest>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowWorkDoneProgressCreate(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WindowWorkDoneProgressCreate>(
			[this, callback = std::forward<F>(callback)](WorkDoneProgressCreateParams&& params) mutable
			{
				const auto hook = messageHook<requests::WindowWorkDoneProgressCreate>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceApplyEdit(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceApplyEdit>(
			[this, callback = std::forward<F>(callback)](ApplyWorkspaceEditParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceApplyEdit>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceCodeLensRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceCodeLensRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceCodeLensRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceConfiguration(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceConfiguration>(
			[this, callback = std::forward<F>(callback)](ConfigurationParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceConfiguration>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDiagnosticRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceDiagnosticRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceDiagnosticRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceFoldingRangeRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceFoldingRangeRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceFoldingRangeRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceInlayHintRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceInlayHintRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceInlayHintRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceInlineValueRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceInlineValueRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceInlineValueRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceSemanticTokensRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceSemanticTokensRefresh>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceSemanticTokensRefresh>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceTextDocumentContentRefresh(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceTextDocumentContentRefresh>(
			[this, callback = std::forward<F>(callback)](TextDocumentContentRefreshParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceTextDocumentContentRefresh>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceWorkspaceFolders(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<requests::WorkspaceWorkspaceFolders>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::WorkspaceWorkspaceFolders>(*this);
				return callback();
			}
		);
		return *this;
	}

	/*
	 * Incoming notifications
	 */

	template<typename F>
	auto onCancelRequest(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::CancelRequest>(
			[this, callback = std::forward<F>(callback)](CancelParams&& params) mutable
			{
				const auto hook = messageHook<notifications::CancelRequest>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onLogTrace(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::LogTrace>(
			[this, callback = std::forward<F>(callback)](LogTraceParams&& params) mutable
			{
				const auto hook = messageHook<notifications::LogTrace>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onProgress(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::Progress>(
			[this, callback = std::forward<F>(callback)](ProgressParams&& params) mutable
			{
				const auto hook = messageHook<notifications::Progress>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTelemetryEvent(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::TelemetryEvent>(
			[this, callback = std::forward<F>(callback)](LSPAny&& params) mutable
			{
				const auto hook = messageHook<notifications::TelemetryEvent>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentPublishDiagnostics(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::TextDocumentPublishDiagnostics>(
			[this, callback = std::forward<F>(callback)](PublishDiagnosticsParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentPublishDiagnostics>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowLogMessage(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::WindowLogMessage>(
			[this, callback = std::forward<F>(callback)](LogMessageParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WindowLogMessage>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowShowMessage(F&& callback) -> ClientEndpoint&
	{
		messageHandler().on<notifications::WindowShowMessage>(
			[this, callback = std::forward<F>(callback)](ShowMessageParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WindowShowMessage>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}
};

} // namespace lsp
