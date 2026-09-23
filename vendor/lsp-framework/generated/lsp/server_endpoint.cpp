/*#############################################################
 * NOTE: This is a generated file and it shouldn't be modified!
 *#############################################################*/

#include "server_endpoint.h"

namespace lsp{

ServerEndpoint::ServerEndpoint(io::Stream& stream)
	: ServerEndpointBase{stream}
{
}

auto ServerEndpoint::clientRegisterCapability(const RegistrationParams& params) -> RequestResult<ClientRegisterCapabilityResult>
{
	const auto hook = messageHook<requests::ClientRegisterCapability>(*this);
	return messageHandler().sendRequest<requests::ClientRegisterCapability>(params);
}

auto ServerEndpoint::clientUnregisterCapability(const UnregistrationParams& params) -> RequestResult<ClientUnregisterCapabilityResult>
{
	const auto hook = messageHook<requests::ClientUnregisterCapability>(*this);
	return messageHandler().sendRequest<requests::ClientUnregisterCapability>(params);
}

auto ServerEndpoint::windowShowDocument(const ShowDocumentParams& params) -> RequestResult<ShowDocumentResult>
{
	const auto hook = messageHook<requests::WindowShowDocument>(*this);
	return messageHandler().sendRequest<requests::WindowShowDocument>(params);
}

auto ServerEndpoint::windowShowMessageRequest(const ShowMessageRequestParams& params) -> RequestResult<WindowShowMessageRequestResult>
{
	const auto hook = messageHook<requests::WindowShowMessageRequest>(*this);
	return messageHandler().sendRequest<requests::WindowShowMessageRequest>(params);
}

auto ServerEndpoint::windowWorkDoneProgressCreate(const WorkDoneProgressCreateParams& params) -> RequestResult<WindowWorkDoneProgressCreateResult>
{
	const auto hook = messageHook<requests::WindowWorkDoneProgressCreate>(*this);
	return messageHandler().sendRequest<requests::WindowWorkDoneProgressCreate>(params);
}

auto ServerEndpoint::workspaceApplyEdit(const ApplyWorkspaceEditParams& params) -> RequestResult<ApplyWorkspaceEditResult>
{
	const auto hook = messageHook<requests::WorkspaceApplyEdit>(*this);
	return messageHandler().sendRequest<requests::WorkspaceApplyEdit>(params);
}

auto ServerEndpoint::workspaceCodeLensRefresh() -> RequestResult<WorkspaceCodeLensRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceCodeLensRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceCodeLensRefresh>();
}

auto ServerEndpoint::workspaceConfiguration(const ConfigurationParams& params) -> RequestResult<WorkspaceConfigurationResult>
{
	const auto hook = messageHook<requests::WorkspaceConfiguration>(*this);
	return messageHandler().sendRequest<requests::WorkspaceConfiguration>(params);
}

auto ServerEndpoint::workspaceDiagnosticRefresh() -> RequestResult<WorkspaceDiagnosticRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceDiagnosticRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceDiagnosticRefresh>();
}

auto ServerEndpoint::workspaceFoldingRangeRefresh() -> RequestResult<WorkspaceFoldingRangeRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceFoldingRangeRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceFoldingRangeRefresh>();
}

auto ServerEndpoint::workspaceInlayHintRefresh() -> RequestResult<WorkspaceInlayHintRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceInlayHintRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceInlayHintRefresh>();
}

auto ServerEndpoint::workspaceInlineValueRefresh() -> RequestResult<WorkspaceInlineValueRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceInlineValueRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceInlineValueRefresh>();
}

auto ServerEndpoint::workspaceSemanticTokensRefresh() -> RequestResult<WorkspaceSemanticTokensRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceSemanticTokensRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceSemanticTokensRefresh>();
}

auto ServerEndpoint::workspaceTextDocumentContentRefresh(const TextDocumentContentRefreshParams& params) -> RequestResult<WorkspaceTextDocumentContentRefreshResult>
{
	const auto hook = messageHook<requests::WorkspaceTextDocumentContentRefresh>(*this);
	return messageHandler().sendRequest<requests::WorkspaceTextDocumentContentRefresh>(params);
}

auto ServerEndpoint::workspaceWorkspaceFolders() -> RequestResult<WorkspaceWorkspaceFoldersResult>
{
	const auto hook = messageHook<requests::WorkspaceWorkspaceFolders>(*this);
	return messageHandler().sendRequest<requests::WorkspaceWorkspaceFolders>();
}

void ServerEndpoint::cancelRequest(const CancelParams& params)
{
	const auto hook = messageHook<notifications::CancelRequest>(*this);
	messageHandler().sendNotification<notifications::CancelRequest>(params);
}

void ServerEndpoint::logTrace(const LogTraceParams& params)
{
	const auto hook = messageHook<notifications::LogTrace>(*this);
	messageHandler().sendNotification<notifications::LogTrace>(params);
}

void ServerEndpoint::progress(const ProgressParams& params)
{
	const auto hook = messageHook<notifications::Progress>(*this);
	messageHandler().sendNotification<notifications::Progress>(params);
}

void ServerEndpoint::telemetryEvent(const LSPAny& params)
{
	const auto hook = messageHook<notifications::TelemetryEvent>(*this);
	messageHandler().sendNotification<notifications::TelemetryEvent>(params);
}

void ServerEndpoint::textDocumentPublishDiagnostics(const PublishDiagnosticsParams& params)
{
	const auto hook = messageHook<notifications::TextDocumentPublishDiagnostics>(*this);
	messageHandler().sendNotification<notifications::TextDocumentPublishDiagnostics>(params);
}

void ServerEndpoint::windowLogMessage(const LogMessageParams& params)
{
	const auto hook = messageHook<notifications::WindowLogMessage>(*this);
	messageHandler().sendNotification<notifications::WindowLogMessage>(params);
}

void ServerEndpoint::windowShowMessage(const ShowMessageParams& params)
{
	const auto hook = messageHook<notifications::WindowShowMessage>(*this);
	messageHandler().sendNotification<notifications::WindowShowMessage>(params);
}

} // namespace lsp
