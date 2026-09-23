/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#include "client_endpoint.h"

namespace lsp{

ClientEndpoint::ClientEndpoint(io::Stream& stream)
	: ClientEndpointBase{stream}
{
}

auto ClientEndpoint::callHierarchyIncomingCalls(const CallHierarchyIncomingCallsParams& params) -> RequestResult<CallHierarchyIncomingCallsResult>
{
	const auto hook = messageHook<requests::CallHierarchyIncomingCalls>(*this);
	return messageHandler().sendRequest<requests::CallHierarchyIncomingCalls>(params);
}

auto ClientEndpoint::callHierarchyOutgoingCalls(const CallHierarchyOutgoingCallsParams& params) -> RequestResult<CallHierarchyOutgoingCallsResult>
{
	const auto hook = messageHook<requests::CallHierarchyOutgoingCalls>(*this);
	return messageHandler().sendRequest<requests::CallHierarchyOutgoingCalls>(params);
}

auto ClientEndpoint::codeActionResolve(const CodeAction& params) -> RequestResult<CodeAction>
{
	const auto hook = messageHook<requests::CodeActionResolve>(*this);
	return messageHandler().sendRequest<requests::CodeActionResolve>(params);
}

auto ClientEndpoint::codeLensResolve(const CodeLens& params) -> RequestResult<CodeLens>
{
	const auto hook = messageHook<requests::CodeLensResolve>(*this);
	return messageHandler().sendRequest<requests::CodeLensResolve>(params);
}

auto ClientEndpoint::completionItemResolve(const CompletionItem& params) -> RequestResult<CompletionItem>
{
	const auto hook = messageHook<requests::CompletionItemResolve>(*this);
	return messageHandler().sendRequest<requests::CompletionItemResolve>(params);
}

auto ClientEndpoint::documentLinkResolve(const DocumentLink& params) -> RequestResult<DocumentLink>
{
	const auto hook = messageHook<requests::DocumentLinkResolve>(*this);
	return messageHandler().sendRequest<requests::DocumentLinkResolve>(params);
}

auto ClientEndpoint::initialize(const InitializeParams& params) -> RequestResult<InitializeResult>
{
	const auto hook = messageHook<requests::Initialize>(*this);
	return messageHandler().sendRequest<requests::Initialize>(params);
}

auto ClientEndpoint::inlayHintResolve(const InlayHint& params) -> RequestResult<InlayHint>
{
	const auto hook = messageHook<requests::InlayHintResolve>(*this);
	return messageHandler().sendRequest<requests::InlayHintResolve>(params);
}

auto ClientEndpoint::shutdown() -> RequestResult<ShutdownResult>
{
	const auto hook = messageHook<requests::Shutdown>(*this);
	return messageHandler().sendRequest<requests::Shutdown>();
}

auto ClientEndpoint::textDocumentCodeAction(const CodeActionParams& params) -> RequestResult<TextDocumentCodeActionResult>
{
	const auto hook = messageHook<requests::TextDocumentCodeAction>(*this);
	return messageHandler().sendRequest<requests::TextDocumentCodeAction>(params);
}

auto ClientEndpoint::textDocumentCodeLens(const CodeLensParams& params) -> RequestResult<TextDocumentCodeLensResult>
{
	const auto hook = messageHook<requests::TextDocumentCodeLens>(*this);
	return messageHandler().sendRequest<requests::TextDocumentCodeLens>(params);
}

auto ClientEndpoint::textDocumentColorPresentation(const ColorPresentationParams& params) -> RequestResult<TextDocumentColorPresentationResult>
{
	const auto hook = messageHook<requests::TextDocumentColorPresentation>(*this);
	return messageHandler().sendRequest<requests::TextDocumentColorPresentation>(params);
}

auto ClientEndpoint::textDocumentCompletion(const CompletionParams& params) -> RequestResult<TextDocumentCompletionResult>
{
	const auto hook = messageHook<requests::TextDocumentCompletion>(*this);
	return messageHandler().sendRequest<requests::TextDocumentCompletion>(params);
}

auto ClientEndpoint::textDocumentDeclaration(const DeclarationParams& params) -> RequestResult<TextDocumentDeclarationResult>
{
	const auto hook = messageHook<requests::TextDocumentDeclaration>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDeclaration>(params);
}

auto ClientEndpoint::textDocumentDefinition(const DefinitionParams& params) -> RequestResult<TextDocumentDefinitionResult>
{
	const auto hook = messageHook<requests::TextDocumentDefinition>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDefinition>(params);
}

auto ClientEndpoint::textDocumentDiagnostic(const DocumentDiagnosticParams& params) -> RequestResult<DocumentDiagnosticReport>
{
	const auto hook = messageHook<requests::TextDocumentDiagnostic>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDiagnostic>(params);
}

auto ClientEndpoint::textDocumentDocumentColor(const DocumentColorParams& params) -> RequestResult<TextDocumentDocumentColorResult>
{
	const auto hook = messageHook<requests::TextDocumentDocumentColor>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDocumentColor>(params);
}

auto ClientEndpoint::textDocumentDocumentHighlight(const DocumentHighlightParams& params) -> RequestResult<TextDocumentDocumentHighlightResult>
{
	const auto hook = messageHook<requests::TextDocumentDocumentHighlight>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDocumentHighlight>(params);
}

auto ClientEndpoint::textDocumentDocumentLink(const DocumentLinkParams& params) -> RequestResult<TextDocumentDocumentLinkResult>
{
	const auto hook = messageHook<requests::TextDocumentDocumentLink>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDocumentLink>(params);
}

auto ClientEndpoint::textDocumentDocumentSymbol(const DocumentSymbolParams& params) -> RequestResult<TextDocumentDocumentSymbolResult>
{
	const auto hook = messageHook<requests::TextDocumentDocumentSymbol>(*this);
	return messageHandler().sendRequest<requests::TextDocumentDocumentSymbol>(params);
}

auto ClientEndpoint::textDocumentFoldingRange(const FoldingRangeParams& params) -> RequestResult<TextDocumentFoldingRangeResult>
{
	const auto hook = messageHook<requests::TextDocumentFoldingRange>(*this);
	return messageHandler().sendRequest<requests::TextDocumentFoldingRange>(params);
}

auto ClientEndpoint::textDocumentFormatting(const DocumentFormattingParams& params) -> RequestResult<TextDocumentFormattingResult>
{
	const auto hook = messageHook<requests::TextDocumentFormatting>(*this);
	return messageHandler().sendRequest<requests::TextDocumentFormatting>(params);
}

auto ClientEndpoint::textDocumentHover(const HoverParams& params) -> RequestResult<TextDocumentHoverResult>
{
	const auto hook = messageHook<requests::TextDocumentHover>(*this);
	return messageHandler().sendRequest<requests::TextDocumentHover>(params);
}

auto ClientEndpoint::textDocumentImplementation(const ImplementationParams& params) -> RequestResult<TextDocumentImplementationResult>
{
	const auto hook = messageHook<requests::TextDocumentImplementation>(*this);
	return messageHandler().sendRequest<requests::TextDocumentImplementation>(params);
}

auto ClientEndpoint::textDocumentInlayHint(const InlayHintParams& params) -> RequestResult<TextDocumentInlayHintResult>
{
	const auto hook = messageHook<requests::TextDocumentInlayHint>(*this);
	return messageHandler().sendRequest<requests::TextDocumentInlayHint>(params);
}

auto ClientEndpoint::textDocumentInlineCompletion(const InlineCompletionParams& params) -> RequestResult<TextDocumentInlineCompletionResult>
{
	const auto hook = messageHook<requests::TextDocumentInlineCompletion>(*this);
	return messageHandler().sendRequest<requests::TextDocumentInlineCompletion>(params);
}

auto ClientEndpoint::textDocumentInlineValue(const InlineValueParams& params) -> RequestResult<TextDocumentInlineValueResult>
{
	const auto hook = messageHook<requests::TextDocumentInlineValue>(*this);
	return messageHandler().sendRequest<requests::TextDocumentInlineValue>(params);
}

auto ClientEndpoint::textDocumentLinkedEditingRange(const LinkedEditingRangeParams& params) -> RequestResult<TextDocumentLinkedEditingRangeResult>
{
	const auto hook = messageHook<requests::TextDocumentLinkedEditingRange>(*this);
	return messageHandler().sendRequest<requests::TextDocumentLinkedEditingRange>(params);
}

auto ClientEndpoint::textDocumentMoniker(const MonikerParams& params) -> RequestResult<TextDocumentMonikerResult>
{
	const auto hook = messageHook<requests::TextDocumentMoniker>(*this);
	return messageHandler().sendRequest<requests::TextDocumentMoniker>(params);
}

auto ClientEndpoint::textDocumentOnTypeFormatting(const DocumentOnTypeFormattingParams& params) -> RequestResult<TextDocumentOnTypeFormattingResult>
{
	const auto hook = messageHook<requests::TextDocumentOnTypeFormatting>(*this);
	return messageHandler().sendRequest<requests::TextDocumentOnTypeFormatting>(params);
}

auto ClientEndpoint::textDocumentPrepareCallHierarchy(const CallHierarchyPrepareParams& params) -> RequestResult<TextDocumentPrepareCallHierarchyResult>
{
	const auto hook = messageHook<requests::TextDocumentPrepareCallHierarchy>(*this);
	return messageHandler().sendRequest<requests::TextDocumentPrepareCallHierarchy>(params);
}

auto ClientEndpoint::textDocumentPrepareRename(const PrepareRenameParams& params) -> RequestResult<TextDocumentPrepareRenameResult>
{
	const auto hook = messageHook<requests::TextDocumentPrepareRename>(*this);
	return messageHandler().sendRequest<requests::TextDocumentPrepareRename>(params);
}

auto ClientEndpoint::textDocumentPrepareTypeHierarchy(const TypeHierarchyPrepareParams& params) -> RequestResult<TextDocumentPrepareTypeHierarchyResult>
{
	const auto hook = messageHook<requests::TextDocumentPrepareTypeHierarchy>(*this);
	return messageHandler().sendRequest<requests::TextDocumentPrepareTypeHierarchy>(params);
}

auto ClientEndpoint::textDocumentRangeFormatting(const DocumentRangeFormattingParams& params) -> RequestResult<TextDocumentRangeFormattingResult>
{
	const auto hook = messageHook<requests::TextDocumentRangeFormatting>(*this);
	return messageHandler().sendRequest<requests::TextDocumentRangeFormatting>(params);
}

auto ClientEndpoint::textDocumentRangesFormatting(const DocumentRangesFormattingParams& params) -> RequestResult<TextDocumentRangesFormattingResult>
{
	const auto hook = messageHook<requests::TextDocumentRangesFormatting>(*this);
	return messageHandler().sendRequest<requests::TextDocumentRangesFormatting>(params);
}

auto ClientEndpoint::textDocumentReferences(const ReferenceParams& params) -> RequestResult<TextDocumentReferencesResult>
{
	const auto hook = messageHook<requests::TextDocumentReferences>(*this);
	return messageHandler().sendRequest<requests::TextDocumentReferences>(params);
}

auto ClientEndpoint::textDocumentRename(const RenameParams& params) -> RequestResult<TextDocumentRenameResult>
{
	const auto hook = messageHook<requests::TextDocumentRename>(*this);
	return messageHandler().sendRequest<requests::TextDocumentRename>(params);
}

auto ClientEndpoint::textDocumentSelectionRange(const SelectionRangeParams& params) -> RequestResult<TextDocumentSelectionRangeResult>
{
	const auto hook = messageHook<requests::TextDocumentSelectionRange>(*this);
	return messageHandler().sendRequest<requests::TextDocumentSelectionRange>(params);
}

auto ClientEndpoint::textDocumentSemanticTokensFull(const SemanticTokensParams& params) -> RequestResult<TextDocumentSemanticTokensFullResult>
{
	const auto hook = messageHook<requests::TextDocumentSemanticTokensFull>(*this);
	return messageHandler().sendRequest<requests::TextDocumentSemanticTokensFull>(params);
}

auto ClientEndpoint::textDocumentSemanticTokensFullDelta(const SemanticTokensDeltaParams& params) -> RequestResult<TextDocumentSemanticTokensFullDeltaResult>
{
	const auto hook = messageHook<requests::TextDocumentSemanticTokensFullDelta>(*this);
	return messageHandler().sendRequest<requests::TextDocumentSemanticTokensFullDelta>(params);
}

auto ClientEndpoint::textDocumentSemanticTokensRange(const SemanticTokensRangeParams& params) -> RequestResult<TextDocumentSemanticTokensRangeResult>
{
	const auto hook = messageHook<requests::TextDocumentSemanticTokensRange>(*this);
	return messageHandler().sendRequest<requests::TextDocumentSemanticTokensRange>(params);
}

auto ClientEndpoint::textDocumentSignatureHelp(const SignatureHelpParams& params) -> RequestResult<TextDocumentSignatureHelpResult>
{
	const auto hook = messageHook<requests::TextDocumentSignatureHelp>(*this);
	return messageHandler().sendRequest<requests::TextDocumentSignatureHelp>(params);
}

auto ClientEndpoint::textDocumentTypeDefinition(const TypeDefinitionParams& params) -> RequestResult<TextDocumentTypeDefinitionResult>
{
	const auto hook = messageHook<requests::TextDocumentTypeDefinition>(*this);
	return messageHandler().sendRequest<requests::TextDocumentTypeDefinition>(params);
}

auto ClientEndpoint::textDocumentWillSaveWaitUntil(const WillSaveTextDocumentParams& params) -> RequestResult<TextDocumentWillSaveWaitUntilResult>
{
	const auto hook = messageHook<requests::TextDocumentWillSaveWaitUntil>(*this);
	return messageHandler().sendRequest<requests::TextDocumentWillSaveWaitUntil>(params);
}

auto ClientEndpoint::typeHierarchySubtypes(const TypeHierarchySubtypesParams& params) -> RequestResult<TypeHierarchySubtypesResult>
{
	const auto hook = messageHook<requests::TypeHierarchySubtypes>(*this);
	return messageHandler().sendRequest<requests::TypeHierarchySubtypes>(params);
}

auto ClientEndpoint::typeHierarchySupertypes(const TypeHierarchySupertypesParams& params) -> RequestResult<TypeHierarchySupertypesResult>
{
	const auto hook = messageHook<requests::TypeHierarchySupertypes>(*this);
	return messageHandler().sendRequest<requests::TypeHierarchySupertypes>(params);
}

auto ClientEndpoint::workspaceDiagnostic(const WorkspaceDiagnosticParams& params) -> RequestResult<WorkspaceDiagnosticReport>
{
	const auto hook = messageHook<requests::WorkspaceDiagnostic>(*this);
	return messageHandler().sendRequest<requests::WorkspaceDiagnostic>(params);
}

auto ClientEndpoint::workspaceExecuteCommand(const ExecuteCommandParams& params) -> RequestResult<WorkspaceExecuteCommandResult>
{
	const auto hook = messageHook<requests::WorkspaceExecuteCommand>(*this);
	return messageHandler().sendRequest<requests::WorkspaceExecuteCommand>(params);
}

auto ClientEndpoint::workspaceSymbol(const WorkspaceSymbolParams& params) -> RequestResult<WorkspaceSymbolResult>
{
	const auto hook = messageHook<requests::WorkspaceSymbol>(*this);
	return messageHandler().sendRequest<requests::WorkspaceSymbol>(params);
}

auto ClientEndpoint::workspaceTextDocumentContent(const TextDocumentContentParams& params) -> RequestResult<TextDocumentContentResult>
{
	const auto hook = messageHook<requests::WorkspaceTextDocumentContent>(*this);
	return messageHandler().sendRequest<requests::WorkspaceTextDocumentContent>(params);
}

auto ClientEndpoint::workspaceWillCreateFiles(const CreateFilesParams& params) -> RequestResult<WorkspaceWillCreateFilesResult>
{
	const auto hook = messageHook<requests::WorkspaceWillCreateFiles>(*this);
	return messageHandler().sendRequest<requests::WorkspaceWillCreateFiles>(params);
}

auto ClientEndpoint::workspaceWillDeleteFiles(const DeleteFilesParams& params) -> RequestResult<WorkspaceWillDeleteFilesResult>
{
	const auto hook = messageHook<requests::WorkspaceWillDeleteFiles>(*this);
	return messageHandler().sendRequest<requests::WorkspaceWillDeleteFiles>(params);
}

auto ClientEndpoint::workspaceWillRenameFiles(const RenameFilesParams& params) -> RequestResult<WorkspaceWillRenameFilesResult>
{
	const auto hook = messageHook<requests::WorkspaceWillRenameFiles>(*this);
	return messageHandler().sendRequest<requests::WorkspaceWillRenameFiles>(params);
}

auto ClientEndpoint::workspaceSymbolResolve(const WorkspaceSymbol& params) -> RequestResult<WorkspaceSymbol>
{
	const auto hook = messageHook<requests::WorkspaceSymbolResolve>(*this);
	return messageHandler().sendRequest<requests::WorkspaceSymbolResolve>(params);
}

void ClientEndpoint::cancelRequest(const CancelParams& params)
{
	const auto hook = messageHook<notifications::CancelRequest>(*this);
	messageHandler().sendNotification<notifications::CancelRequest>(params);
}

void ClientEndpoint::progress(const ProgressParams& params)
{
	const auto hook = messageHook<notifications::Progress>(*this);
	messageHandler().sendNotification<notifications::Progress>(params);
}

void ClientEndpoint::setTrace(const SetTraceParams& params)
{
	const auto hook = messageHook<notifications::SetTrace>(*this);
	messageHandler().sendNotification<notifications::SetTrace>(params);
}

void ClientEndpoint::exit()
{
	const auto hook = messageHook<notifications::Exit>(*this);
	messageHandler().sendNotification<notifications::Exit>();
}

void ClientEndpoint::initialized(const InitializedParams& params)
{
	const auto hook = messageHook<notifications::Initialized>(*this);
	messageHandler().sendNotification<notifications::Initialized>(params);
}

void ClientEndpoint::notebookDocumentDidChange(const DidChangeNotebookDocumentParams& params)
{
	const auto hook = messageHook<notifications::NotebookDocumentDidChange>(*this);
	messageHandler().sendNotification<notifications::NotebookDocumentDidChange>(params);
}

void ClientEndpoint::notebookDocumentDidClose(const DidCloseNotebookDocumentParams& params)
{
	const auto hook = messageHook<notifications::NotebookDocumentDidClose>(*this);
	messageHandler().sendNotification<notifications::NotebookDocumentDidClose>(params);
}

void ClientEndpoint::notebookDocumentDidOpen(const DidOpenNotebookDocumentParams& params)
{
	const auto hook = messageHook<notifications::NotebookDocumentDidOpen>(*this);
	messageHandler().sendNotification<notifications::NotebookDocumentDidOpen>(params);
}

void ClientEndpoint::notebookDocumentDidSave(const DidSaveNotebookDocumentParams& params)
{
	const auto hook = messageHook<notifications::NotebookDocumentDidSave>(*this);
	messageHandler().sendNotification<notifications::NotebookDocumentDidSave>(params);
}

void ClientEndpoint::textDocumentDidChange(const DidChangeTextDocumentParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentDidChange>(*this);
	messageHandler().sendNotification<notifications::TextDocumentDidChange>(params);
}

void ClientEndpoint::textDocumentDidClose(const DidCloseTextDocumentParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentDidClose>(*this);
	messageHandler().sendNotification<notifications::TextDocumentDidClose>(params);
}

void ClientEndpoint::textDocumentDidOpen(const DidOpenTextDocumentParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentDidOpen>(*this);
	messageHandler().sendNotification<notifications::TextDocumentDidOpen>(params);
}

void ClientEndpoint::textDocumentDidSave(const DidSaveTextDocumentParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentDidSave>(*this);
	messageHandler().sendNotification<notifications::TextDocumentDidSave>(params);
}

void ClientEndpoint::textDocumentWillSave(const WillSaveTextDocumentParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentWillSave>(*this);
	messageHandler().sendNotification<notifications::TextDocumentWillSave>(params);
}

void ClientEndpoint::windowWorkDoneProgressCancel(const WorkDoneProgressCancelParams& params)
{
	const auto hook = messageHook<notifications::WindowWorkDoneProgressCancel>(*this);
	messageHandler().sendNotification<notifications::WindowWorkDoneProgressCancel>(params);
}

void ClientEndpoint::workspaceDidChangeConfiguration(const DidChangeConfigurationParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidChangeConfiguration>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidChangeConfiguration>(params);
}

void ClientEndpoint::workspaceDidChangeWatchedFiles(const DidChangeWatchedFilesParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidChangeWatchedFiles>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidChangeWatchedFiles>(params);
}

void ClientEndpoint::workspaceDidChangeWorkspaceFolders(const DidChangeWorkspaceFoldersParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidChangeWorkspaceFolders>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidChangeWorkspaceFolders>(params);
}

void ClientEndpoint::workspaceDidCreateFiles(const CreateFilesParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidCreateFiles>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidCreateFiles>(params);
}

void ClientEndpoint::workspaceDidDeleteFiles(const DeleteFilesParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidDeleteFiles>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidDeleteFiles>(params);
}

void ClientEndpoint::workspaceDidRenameFiles(const RenameFilesParams& params)
{
	const auto hook = messageHook<notifications::WorkspaceDidRenameFiles>(*this);
	messageHandler().sendNotification<notifications::WorkspaceDidRenameFiles>(params);
}

} // namespace lsp
