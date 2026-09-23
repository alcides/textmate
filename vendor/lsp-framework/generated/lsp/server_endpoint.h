/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#pragma once

#include <lsp/endpoint_base.h>
#include <lsp/messages.h>

namespace lsp{

class ServerEndpoint : public ServerEndpointBase{
public:
	ServerEndpoint(io::Stream& stream);

	/*
	 * Outgoing requests
	 */

	[[nodiscard]] auto clientRegisterCapability(const RegistrationParams& params) -> RequestResult<ClientRegisterCapabilityResult>;
	[[nodiscard]] auto clientUnregisterCapability(const UnregistrationParams& params) -> RequestResult<ClientUnregisterCapabilityResult>;
	[[nodiscard]] auto windowShowDocument(const ShowDocumentParams& params) -> RequestResult<ShowDocumentResult>;
	[[nodiscard]] auto windowShowMessageRequest(const ShowMessageRequestParams& params) -> RequestResult<WindowShowMessageRequestResult>;
	[[nodiscard]] auto windowWorkDoneProgressCreate(const WorkDoneProgressCreateParams& params) -> RequestResult<WindowWorkDoneProgressCreateResult>;
	[[nodiscard]] auto workspaceApplyEdit(const ApplyWorkspaceEditParams& params) -> RequestResult<ApplyWorkspaceEditResult>;
	[[nodiscard]] auto workspaceCodeLensRefresh() -> RequestResult<WorkspaceCodeLensRefreshResult>;
	[[nodiscard]] auto workspaceConfiguration(const ConfigurationParams& params) -> RequestResult<WorkspaceConfigurationResult>;
	[[nodiscard]] auto workspaceDiagnosticRefresh() -> RequestResult<WorkspaceDiagnosticRefreshResult>;
	[[nodiscard]] auto workspaceFoldingRangeRefresh() -> RequestResult<WorkspaceFoldingRangeRefreshResult>;
	[[nodiscard]] auto workspaceInlayHintRefresh() -> RequestResult<WorkspaceInlayHintRefreshResult>;
	[[nodiscard]] auto workspaceInlineValueRefresh() -> RequestResult<WorkspaceInlineValueRefreshResult>;
	[[nodiscard]] auto workspaceSemanticTokensRefresh() -> RequestResult<WorkspaceSemanticTokensRefreshResult>;
	[[nodiscard]] auto workspaceTextDocumentContentRefresh(const TextDocumentContentRefreshParams& params) -> RequestResult<WorkspaceTextDocumentContentRefreshResult>;
	[[nodiscard]] auto workspaceWorkspaceFolders() -> RequestResult<WorkspaceWorkspaceFoldersResult>;

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto clientRegisterCapability(const RegistrationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::ClientRegisterCapability>(*this);
		return messageHandler().sendRequest<requests::ClientRegisterCapability>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto clientUnregisterCapability(const UnregistrationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::ClientUnregisterCapability>(*this);
		return messageHandler().sendRequest<requests::ClientUnregisterCapability>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto windowShowDocument(const ShowDocumentParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WindowShowDocument>(*this);
		return messageHandler().sendRequest<requests::WindowShowDocument>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto windowShowMessageRequest(const ShowMessageRequestParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WindowShowMessageRequest>(*this);
		return messageHandler().sendRequest<requests::WindowShowMessageRequest>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto windowWorkDoneProgressCreate(const WorkDoneProgressCreateParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WindowWorkDoneProgressCreate>(*this);
		return messageHandler().sendRequest<requests::WindowWorkDoneProgressCreate>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceApplyEdit(const ApplyWorkspaceEditParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceApplyEdit>(*this);
		return messageHandler().sendRequest<requests::WorkspaceApplyEdit>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceCodeLensRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceCodeLensRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceCodeLensRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceConfiguration(const ConfigurationParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceConfiguration>(*this);
		return messageHandler().sendRequest<requests::WorkspaceConfiguration>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceDiagnosticRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceDiagnosticRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceDiagnosticRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceFoldingRangeRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceFoldingRangeRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceFoldingRangeRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceInlayHintRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceInlayHintRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceInlayHintRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceInlineValueRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceInlineValueRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceInlineValueRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceSemanticTokensRefresh(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceSemanticTokensRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceSemanticTokensRefresh>(std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceTextDocumentContentRefresh(const TextDocumentContentRefreshParams& params, F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceTextDocumentContentRefresh>(*this);
		return messageHandler().sendRequest<requests::WorkspaceTextDocumentContentRefresh>(params, std::forward<F>(then), std::forward<E>(error));
	}

	template<typename F, typename E = MessageHandler::ResponseErrorCallback>
	auto workspaceWorkspaceFolders(F&& then, E&& error = nullError) -> RequestId
	{
		const auto hook = messageHook<requests::WorkspaceWorkspaceFolders>(*this);
		return messageHandler().sendRequest<requests::WorkspaceWorkspaceFolders>(std::forward<F>(then), std::forward<E>(error));
	}

	/*
	 * Outgoing notifications
	 */

	void cancelRequest(const CancelParams& params);
	void logTrace(const LogTraceParams& params);
	void progress(const ProgressParams& params);
	void telemetryEvent(const LSPAny& params);
	void textDocumentPublishDiagnostics(const PublishDiagnosticsParams& params);
	void windowLogMessage(const LogMessageParams& params);
	void windowShowMessage(const ShowMessageParams& params);
	

	/*
	 * Incoming requests
	 */

	template<typename F>
	auto onCallHierarchyIncomingCalls(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::CallHierarchyIncomingCalls>(
			[this, callback = std::forward<F>(callback)](CallHierarchyIncomingCallsParams&& params) mutable
			{
				const auto hook = messageHook<requests::CallHierarchyIncomingCalls>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onCallHierarchyOutgoingCalls(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::CallHierarchyOutgoingCalls>(
			[this, callback = std::forward<F>(callback)](CallHierarchyOutgoingCallsParams&& params) mutable
			{
				const auto hook = messageHook<requests::CallHierarchyOutgoingCalls>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onCodeActionResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::CodeActionResolve>(
			[this, callback = std::forward<F>(callback)](CodeAction&& params) mutable
			{
				const auto hook = messageHook<requests::CodeActionResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onCodeLensResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::CodeLensResolve>(
			[this, callback = std::forward<F>(callback)](CodeLens&& params) mutable
			{
				const auto hook = messageHook<requests::CodeLensResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onCompletionItemResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::CompletionItemResolve>(
			[this, callback = std::forward<F>(callback)](CompletionItem&& params) mutable
			{
				const auto hook = messageHook<requests::CompletionItemResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onDocumentLinkResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::DocumentLinkResolve>(
			[this, callback = std::forward<F>(callback)](DocumentLink&& params) mutable
			{
				const auto hook = messageHook<requests::DocumentLinkResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onInitialize(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::Initialize>(
			[this, callback = std::forward<F>(callback)](InitializeParams&& params) mutable
			{
				const auto hook = messageHook<requests::Initialize>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onInlayHintResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::InlayHintResolve>(
			[this, callback = std::forward<F>(callback)](InlayHint&& params) mutable
			{
				const auto hook = messageHook<requests::InlayHintResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onShutdown(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::Shutdown>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<requests::Shutdown>(*this);
				return callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentCodeAction(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentCodeAction>(
			[this, callback = std::forward<F>(callback)](CodeActionParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentCodeAction>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentCodeLens(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentCodeLens>(
			[this, callback = std::forward<F>(callback)](CodeLensParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentCodeLens>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentColorPresentation(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentColorPresentation>(
			[this, callback = std::forward<F>(callback)](ColorPresentationParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentColorPresentation>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentCompletion(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentCompletion>(
			[this, callback = std::forward<F>(callback)](CompletionParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentCompletion>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDeclaration(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDeclaration>(
			[this, callback = std::forward<F>(callback)](DeclarationParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDeclaration>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDefinition(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDefinition>(
			[this, callback = std::forward<F>(callback)](DefinitionParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDefinition>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDiagnostic(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDiagnostic>(
			[this, callback = std::forward<F>(callback)](DocumentDiagnosticParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDiagnostic>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDocumentColor(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDocumentColor>(
			[this, callback = std::forward<F>(callback)](DocumentColorParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDocumentColor>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDocumentHighlight(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDocumentHighlight>(
			[this, callback = std::forward<F>(callback)](DocumentHighlightParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDocumentHighlight>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDocumentLink(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDocumentLink>(
			[this, callback = std::forward<F>(callback)](DocumentLinkParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDocumentLink>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDocumentSymbol(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentDocumentSymbol>(
			[this, callback = std::forward<F>(callback)](DocumentSymbolParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentDocumentSymbol>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentFoldingRange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentFoldingRange>(
			[this, callback = std::forward<F>(callback)](FoldingRangeParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentFoldingRange>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentFormatting(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentFormatting>(
			[this, callback = std::forward<F>(callback)](DocumentFormattingParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentFormatting>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentHover(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentHover>(
			[this, callback = std::forward<F>(callback)](HoverParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentHover>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentImplementation(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentImplementation>(
			[this, callback = std::forward<F>(callback)](ImplementationParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentImplementation>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentInlayHint(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentInlayHint>(
			[this, callback = std::forward<F>(callback)](InlayHintParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentInlayHint>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentInlineCompletion(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentInlineCompletion>(
			[this, callback = std::forward<F>(callback)](InlineCompletionParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentInlineCompletion>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentInlineValue(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentInlineValue>(
			[this, callback = std::forward<F>(callback)](InlineValueParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentInlineValue>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentLinkedEditingRange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentLinkedEditingRange>(
			[this, callback = std::forward<F>(callback)](LinkedEditingRangeParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentLinkedEditingRange>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentMoniker(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentMoniker>(
			[this, callback = std::forward<F>(callback)](MonikerParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentMoniker>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentOnTypeFormatting(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentOnTypeFormatting>(
			[this, callback = std::forward<F>(callback)](DocumentOnTypeFormattingParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentOnTypeFormatting>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentPrepareCallHierarchy(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentPrepareCallHierarchy>(
			[this, callback = std::forward<F>(callback)](CallHierarchyPrepareParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentPrepareCallHierarchy>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentPrepareRename(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentPrepareRename>(
			[this, callback = std::forward<F>(callback)](PrepareRenameParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentPrepareRename>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentPrepareTypeHierarchy(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentPrepareTypeHierarchy>(
			[this, callback = std::forward<F>(callback)](TypeHierarchyPrepareParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentPrepareTypeHierarchy>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentRangeFormatting(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentRangeFormatting>(
			[this, callback = std::forward<F>(callback)](DocumentRangeFormattingParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentRangeFormatting>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentRangesFormatting(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentRangesFormatting>(
			[this, callback = std::forward<F>(callback)](DocumentRangesFormattingParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentRangesFormatting>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentReferences(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentReferences>(
			[this, callback = std::forward<F>(callback)](ReferenceParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentReferences>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentRename(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentRename>(
			[this, callback = std::forward<F>(callback)](RenameParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentRename>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentSelectionRange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentSelectionRange>(
			[this, callback = std::forward<F>(callback)](SelectionRangeParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentSelectionRange>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentSemanticTokensFull(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentSemanticTokensFull>(
			[this, callback = std::forward<F>(callback)](SemanticTokensParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentSemanticTokensFull>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentSemanticTokensFullDelta(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentSemanticTokensFullDelta>(
			[this, callback = std::forward<F>(callback)](SemanticTokensDeltaParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentSemanticTokensFullDelta>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentSemanticTokensRange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentSemanticTokensRange>(
			[this, callback = std::forward<F>(callback)](SemanticTokensRangeParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentSemanticTokensRange>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentSignatureHelp(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentSignatureHelp>(
			[this, callback = std::forward<F>(callback)](SignatureHelpParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentSignatureHelp>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentTypeDefinition(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentTypeDefinition>(
			[this, callback = std::forward<F>(callback)](TypeDefinitionParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentTypeDefinition>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentWillSaveWaitUntil(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TextDocumentWillSaveWaitUntil>(
			[this, callback = std::forward<F>(callback)](WillSaveTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<requests::TextDocumentWillSaveWaitUntil>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTypeHierarchySubtypes(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TypeHierarchySubtypes>(
			[this, callback = std::forward<F>(callback)](TypeHierarchySubtypesParams&& params) mutable
			{
				const auto hook = messageHook<requests::TypeHierarchySubtypes>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTypeHierarchySupertypes(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::TypeHierarchySupertypes>(
			[this, callback = std::forward<F>(callback)](TypeHierarchySupertypesParams&& params) mutable
			{
				const auto hook = messageHook<requests::TypeHierarchySupertypes>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDiagnostic(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceDiagnostic>(
			[this, callback = std::forward<F>(callback)](WorkspaceDiagnosticParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceDiagnostic>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceExecuteCommand(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceExecuteCommand>(
			[this, callback = std::forward<F>(callback)](ExecuteCommandParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceExecuteCommand>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceSymbol(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceSymbol>(
			[this, callback = std::forward<F>(callback)](WorkspaceSymbolParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceSymbol>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceTextDocumentContent(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceTextDocumentContent>(
			[this, callback = std::forward<F>(callback)](TextDocumentContentParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceTextDocumentContent>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceWillCreateFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceWillCreateFiles>(
			[this, callback = std::forward<F>(callback)](CreateFilesParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceWillCreateFiles>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceWillDeleteFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceWillDeleteFiles>(
			[this, callback = std::forward<F>(callback)](DeleteFilesParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceWillDeleteFiles>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceWillRenameFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceWillRenameFiles>(
			[this, callback = std::forward<F>(callback)](RenameFilesParams&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceWillRenameFiles>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceSymbolResolve(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<requests::WorkspaceSymbolResolve>(
			[this, callback = std::forward<F>(callback)](WorkspaceSymbol&& params) mutable
			{
				const auto hook = messageHook<requests::WorkspaceSymbolResolve>(*this);
				return callback(std::move(params));
			}
		);
		return *this;
	}

	/*
	 * Incoming notifications
	 */

	template<typename F>
	auto onCancelRequest(F&& callback) -> ServerEndpoint&
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
	auto onProgress(F&& callback) -> ServerEndpoint&
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
	auto onSetTrace(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::SetTrace>(
			[this, callback = std::forward<F>(callback)](SetTraceParams&& params) mutable
			{
				const auto hook = messageHook<notifications::SetTrace>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onExit(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::Exit>(
			[this, callback = std::forward<F>(callback)]() mutable
			{
				const auto hook = messageHook<notifications::Exit>(*this);
				callback();
			}
		);
		return *this;
	}

	template<typename F>
	auto onInitialized(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::Initialized>(
			[this, callback = std::forward<F>(callback)](InitializedParams&& params) mutable
			{
				const auto hook = messageHook<notifications::Initialized>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onNotebookDocumentDidChange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::NotebookDocumentDidChange>(
			[this, callback = std::forward<F>(callback)](DidChangeNotebookDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::NotebookDocumentDidChange>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onNotebookDocumentDidClose(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::NotebookDocumentDidClose>(
			[this, callback = std::forward<F>(callback)](DidCloseNotebookDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::NotebookDocumentDidClose>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onNotebookDocumentDidOpen(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::NotebookDocumentDidOpen>(
			[this, callback = std::forward<F>(callback)](DidOpenNotebookDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::NotebookDocumentDidOpen>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onNotebookDocumentDidSave(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::NotebookDocumentDidSave>(
			[this, callback = std::forward<F>(callback)](DidSaveNotebookDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::NotebookDocumentDidSave>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDidChange(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::TextDocumentDidChange>(
			[this, callback = std::forward<F>(callback)](DidChangeTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentDidChange>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDidClose(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::TextDocumentDidClose>(
			[this, callback = std::forward<F>(callback)](DidCloseTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentDidClose>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDidOpen(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::TextDocumentDidOpen>(
			[this, callback = std::forward<F>(callback)](DidOpenTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentDidOpen>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentDidSave(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::TextDocumentDidSave>(
			[this, callback = std::forward<F>(callback)](DidSaveTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentDidSave>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onTextDocumentWillSave(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::TextDocumentWillSave>(
			[this, callback = std::forward<F>(callback)](WillSaveTextDocumentParams&& params) mutable
			{
				const auto hook = messageHook<notifications::TextDocumentWillSave>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWindowWorkDoneProgressCancel(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WindowWorkDoneProgressCancel>(
			[this, callback = std::forward<F>(callback)](WorkDoneProgressCancelParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WindowWorkDoneProgressCancel>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidChangeConfiguration(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidChangeConfiguration>(
			[this, callback = std::forward<F>(callback)](DidChangeConfigurationParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidChangeConfiguration>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidChangeWatchedFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidChangeWatchedFiles>(
			[this, callback = std::forward<F>(callback)](DidChangeWatchedFilesParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidChangeWatchedFiles>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidChangeWorkspaceFolders(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidChangeWorkspaceFolders>(
			[this, callback = std::forward<F>(callback)](DidChangeWorkspaceFoldersParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidChangeWorkspaceFolders>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidCreateFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidCreateFiles>(
			[this, callback = std::forward<F>(callback)](CreateFilesParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidCreateFiles>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidDeleteFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidDeleteFiles>(
			[this, callback = std::forward<F>(callback)](DeleteFilesParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidDeleteFiles>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}

	template<typename F>
	auto onWorkspaceDidRenameFiles(F&& callback) -> ServerEndpoint&
	{
		messageHandler().on<notifications::WorkspaceDidRenameFiles>(
			[this, callback = std::forward<F>(callback)](RenameFilesParams&& params) mutable
			{
				const auto hook = messageHook<notifications::WorkspaceDidRenameFiles>(*this);
				callback(std::move(params));
			}
		);
		return *this;
	}
};

} // namespace lsp
