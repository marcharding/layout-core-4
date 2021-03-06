<?hh //strict

namespace LayoutCore\Api\Resources;

use Plenty\Plugin\Http\Request;
use Illuminate\Http\Response;
use LayoutCore\Api\ApiResource;
use LayoutCore\Api\ApiResponse;
use LayoutCore\Api\ResponseCode;
use LayoutCore\Services\AuthenticationService;

class CustomerLogoutResource extends ApiResource
{
    private AuthenticationService $authService;

    public function __construct(Request $request, ApiResponse $response, AuthenticationService $authService )
    {
        parent::__construct( $request, $response );
        $this->authService = $authService;
    }

    public function index():Response
    {
        $this->authService->logout();
        return $this->response->create(ResponseCode::OK);
    }

}
